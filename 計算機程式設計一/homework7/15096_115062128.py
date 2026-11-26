import sys
from abc import abstractmethod
from typing import List, Optional


class Soldier:
    K = 0

    def __init__(
        self,
        soldier_id: str,
        team: str,
        hp: int,
        speed: int,
        damage: int,
        attack_range: int,
        armor: int,
        row: int,
        col: int,
    ):
        # All soldiers share these attributes.
        self.id = soldier_id
        self.team = team
        self.hp = hp
        self.speed = speed
        self.damage = damage
        self.attack_range = attack_range
        self.armor = armor
        self.row = row
        self.col = col

    @property
    def hp(self):
        return self._hp

    @hp.setter
    def hp(self, value):
        self._hp = max(value, 0)

    @classmethod
    def set_K(cls, value: int):
        cls.K = value

    def is_alive(self):
        # TODO: Return whether this soldier is alive.
        return self.hp > 0

    def distance_to(self, other: "Soldier"):
        # TODO: Return Manhattan distance to other.
        return abs(self.row - other.row) + abs(self.col - other.col)

    def find_target(self, enemies: List["Soldier"]) -> Optional["Soldier"]:
        # TODO: Choose closest living enemy; ties -> smaller ID.
        alive_enemies = list(filter(lambda e: e.is_alive(), enemies))
        alive_enemies.sort(key=lambda x: (self.distance_to(x), x.id))
        if alive_enemies:
            return alive_enemies[0]
        else:
            return None

    def take_damage(self, raw_damage: int) -> None:
        # TODO: Armor reduction, floor, minimum 1; HP cannot go below 0.
        real_damage = max(1, (self.K * raw_damage) // (self.K + self.armor))
        self.hp -= real_damage

    def move_toward(self, target: "Soldier") -> bool:
        D = self.distance_to(target)
        R = self.attack_range
        S = self.speed

        if D <= R:
            return True

        steps = min(S, D - R)

        row_diff = target.row - self.row
        row_steps = min(abs(row_diff), steps)

        if row_diff > 0:
            self.row += row_steps
        else:
            self.row -= row_steps

        steps -= row_steps

        col_diff = target.col - self.col
        col_steps = min(abs(col_diff), steps)

        if col_diff > 0:
            self.col += col_steps
        else:
            self.col -= col_steps

        return self.distance_to(target) <= R

    def attack(self, target: "Soldier"):
        # TODO: Attack target once if target is alive and in range.
        target.take_damage(self.damage)

    def act(self, enemies: List["Soldier"]):
        # TODO: Pick target, then attack or move (and attack if in range).
        target = self.find_target(enemies)
        if target:
            res = self.move_toward(target)
            if res:
                self.attack(target)
        else:
            return

    def __repr__(self) -> str:
        return str(self.id)

    @abstractmethod
    def apply_bonus(self, bonus: int):
        pass


class Cavalry(Soldier):
    def apply_bonus(self, bonus: int):
        # TODO: Multiply movement speed by bonus.
        self.speed *= bonus


class Infantry(Soldier):
    def apply_bonus(self, bonus: int):
        # TODO: Multiply initial HP by bonus.
        self.hp *= bonus


class Archer(Soldier):
    def apply_bonus(self, bonus: int):
        # TODO: Multiply attack range by bonus.
        self.attack_range *= bonus


class Battlefield:
    def __init__(self, red: List["Soldier"], blue: List["Soldier"]):
        self.red = red
        self.blue = blue

    def run_phase(self, allies: List["Soldier"], enemies: List["Soldier"]):
        # TODO: Each living ally acts in input order.
        for people in allies:
            if people.is_alive():
                people.act(enemies)

    def simulate(self, t: int):
        # TODO: Run T seconds; Red phase before Blue phase.
        for turn in range(1, t + 1):
            self.run_phase(self.red, self.blue)
            self.run_phase(self.blue, self.red)

    def results(self):
        # Provided output helper; do not change the format.
        return "\n".join(
            f"{unit.hp} {unit.row} {unit.col}" for unit in self.red + self.blue
        )


def read_soldier(soldier_id, team, bonuses) -> "Soldier":
    parts = sys.stdin.buffer.readline().split()
    kind = parts[0].decode()
    hp, speed, damage, attack_range, armor, row, col = map(int, parts[1:])
    classes = {"C": Cavalry, "I": Infantry, "A": Archer}
    soldier = classes[kind](
        soldier_id, team, hp, speed, damage, attack_range, armor, row, col
    )
    soldier.apply_bonus(bonuses[kind])
    return soldier


def main():
    n, m, p1, p2, t = map(int, sys.stdin.buffer.readline().split())
    k, c_bonus, i_bonus, a_bonus = map(int, sys.stdin.buffer.readline().split())
    bonuses = {"C": c_bonus, "I": i_bonus, "A": a_bonus}

    red = [read_soldier(i, "R", bonuses) for i in range(1, p1 + 1)]
    blue = [read_soldier(p1 + i, "B", bonuses) for i in range(1, p2 + 1)]
    Soldier.set_K(k)

    battlefield = Battlefield(red, blue)
    battlefield.simulate(t)
    sys.stdout.write(battlefield.results() + "\n")


if __name__ == "__main__":
    main()
