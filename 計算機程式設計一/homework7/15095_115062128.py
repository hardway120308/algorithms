import sys
from abc import ABC, abstractmethod
from typing import Dict, List, Optional, Type


class Skill:
    def __init__(
        self, name: str, skill_type: str, power: int, max_cd: int, max_pp: int
    ):
        # TODO
        self.name = name
        self.skill_type = skill_type
        self.power = power
        self.max_cd = max_cd
        self.max_pp = max_pp
        self.current_cd = 0
        self.current_pp = max_pp

    @property
    def current_cd(self) -> int:
        # TODO
        return self._current_cd

    @current_cd.setter
    def current_cd(self, value: int) -> None:
        # TODO
        self._current_cd = max(0, min(value, self.max_cd))

    @property
    def current_pp(self) -> int:
        # TODO
        return self._current_pp

    @current_pp.setter
    def current_pp(self, value: int) -> None:
        # TODO
        self._current_pp = max(0, min(value, self.max_pp))

    @property
    def is_available(self) -> bool:
        # TODO
        return self.current_cd == 0 and self.current_pp > 0

    def consume(self) -> None:
        # TODO
        self.current_pp -= 1
        self.current_cd = self.max_cd

    def next_tick(self) -> None:
        # TODO
        self.current_cd -= 1

    @classmethod
    def from_string(cls, line: str) -> "Skill":
        # TODO
        values = line.split()
        return Skill(
            values[0], values[1], int(values[2]), int(values[3]), int(values[4])
        )

    def __repr__(self) -> str:
        return self.name


class Pokemon(ABC):
    def __init__(
        self, name: str, max_hp: int, atk: int, defense: int, skills: List[Skill]
    ):
        # TODO
        self.name = name
        self.max_hp = max_hp
        self.hp = self.max_hp
        self.atk = atk
        self.defense = defense
        self.skills = skills

    @property
    def hp(self) -> int:
        # TODO
        return self._hp

    @hp.setter
    def hp(self, value: int) -> None:
        # TODO
        self._hp = max(0, min(value, self.max_hp))

    @property
    def is_alive(self) -> bool:
        # TODO
        return self.hp > 0

    def get_available_skills(self) -> List[Skill]:
        # TODO
        return list(filter(lambda s: s.is_available, self.skills))

    def heal(self, amount: int) -> None:
        # TODO
        self.hp += amount

    def take_damage(self, raw_dmg: int, ignore_def_half: bool = False) -> int:
        # TODO
        effective_def = (self.defense // 2) if ignore_def_half else self.defense
        actual_dmg = max(1, raw_dmg - effective_def)
        self.hp -= actual_dmg
        return actual_dmg

    def struggle(self, target: "Pokemon") -> None:
        # TODO
        raw_dmg = max(1, self.atk // 2)
        target.take_damage(raw_dmg)

    @abstractmethod
    def execute_skill(self, skill: Skill, target: "Pokemon") -> None:
        pass

    @classmethod
    def create(
        cls,
        poke_type: str,
        poke_name: str,
        max_hp: int,
        atk: int,
        defense: int,
        skills: List[Skill],
    ) -> "Pokemon":
        # TODO
        if poke_type == "Power":
            return PowerPokemon(poke_name, max_hp, atk, defense, skills)
        elif poke_type == "Mystic":
            return MysticPokemon(poke_name, max_hp, atk, defense, skills)
        else:
            return TankPokemon(poke_name, max_hp, atk, defense, skills)


class PowerPokemon(Pokemon):
    def execute_skill(self, skill: Skill, target: "Pokemon") -> None:
        # TODO
        if skill.skill_type == "Attack":
            raw_dmg = ((self.atk + skill.power) * 12) // 10
            target.take_damage(raw_dmg)
        elif skill.skill_type == "Pierce":
            raw_dmg = self.atk + skill.power
            target.take_damage(raw_dmg)
        elif skill.skill_type == "Heal":
            self.heal(skill.power)
        skill.consume()


class MysticPokemon(Pokemon):
    def execute_skill(self, skill: Skill, target: "Pokemon") -> None:
        # TODO
        if skill.skill_type == "Attack":
            raw_dmg = self.atk + skill.power
            target.take_damage(raw_dmg)
        elif skill.skill_type == "Pierce":
            raw_dmg = self.atk + skill.power
            target.take_damage(raw_dmg, True)
        elif skill.skill_type == "Heal":
            self.heal(skill.power)
        skill.consume()


class TankPokemon(Pokemon):
    def take_damage(self, raw_dmg: int, ignore_def_half: bool = False) -> int:
        # TODO
        mitigated_raw = (raw_dmg * 8) // 10
        return Pokemon.take_damage(self, mitigated_raw, ignore_def_half)

    def execute_skill(self, skill: Skill, target: "Pokemon") -> None:
        # TODO
        if skill.skill_type == "Pierce" or skill.skill_type == "Attack":
            raw_dmg = self.atk + skill.power
            target.take_damage(raw_dmg)
        elif skill.skill_type == "Heal":
            self.heal((skill.power * 3) // 2)
        skill.consume()


class Hunter(ABC):
    def __init__(self, name: str, nen_type: str, pokemon: Pokemon):
        # TODO
        self.name = name
        self.nen_type = nen_type
        self.pokemon = pokemon
        self.turn_count = 0

    def next_turn(self) -> None:
        self.turn_count += 1

    def take_turn(self, opponent: "Hunter") -> None:
        # TODO
        self.next_turn()
        skill = self.choose_skill(self.pokemon.get_available_skills(), opponent.pokemon)
        if skill:
            self.pokemon.execute_skill(skill, opponent.pokemon)
        else:
            self.pokemon.struggle(opponent.pokemon)

    @abstractmethod
    def choose_skill(
        self, available_skills: List[Skill], enemy_pokemon: Pokemon
    ) -> Optional[Skill]:
        pass

    @classmethod
    def create(cls, nen_type: str, hunter_name: str, pokemon: Pokemon) -> "Hunter":
        # TODO
        if nen_type == "Enhancer":
            return EnhancerHunter(hunter_name, nen_type, pokemon)
        elif nen_type == "Emitter":
            return EmitterHunter(hunter_name, nen_type, pokemon)
        elif nen_type == "Transmuter":
            return TransmuterHunter(hunter_name, nen_type, pokemon)
        elif nen_type == "Manipulator":
            return ManipulatorHunter(hunter_name, nen_type, pokemon)
        elif nen_type == "Conjurer":
            return ConjurerHunter(hunter_name, nen_type, pokemon)
        else:
            return SpecialistHunter(hunter_name, nen_type, pokemon)


class EnhancerHunter(Hunter):
    def choose_skill(
        self, available_skills: List[Skill], enemy_pokemon: Pokemon
    ) -> Optional[Skill]:
        available_skills.sort(key=lambda x: x.power, reverse=True)
        first_options = list(
            filter(
                lambda x: x.skill_type == "Attack" or x.skill_type == "Pierce",
                available_skills,
            )
        )
        if first_options:
            return first_options[0]
        else:
            if available_skills:
                return available_skills[0]
            else:
                return None


class EmitterHunter(Hunter):
    def choose_skill(
        self, available_skills: List[Skill], enemy_pokemon: Pokemon
    ) -> Optional[Skill]:
        available_skills.sort(key=lambda x: x.power, reverse=True)
        pierce_skill = list(
            filter(lambda x: x.skill_type == "Pierce", available_skills)
        )
        if enemy_pokemon.defense >= 15 and pierce_skill:
            return pierce_skill[0]
        else:
            first_options = list(
                filter(
                    lambda x: x.skill_type == "Attack" or x.skill_type == "Pierce",
                    available_skills,
                )
            )
            if first_options:
                return first_options[0]
            else:
                if available_skills:
                    return available_skills[0]
                else:
                    return None


class TransmuterHunter(Hunter):
    def choose_skill(
        self, available_skills: List[Skill], enemy_pokemon: Pokemon
    ) -> Optional[Skill]:
        if self.turn_count % 2 == 1:
            available_skills = list(reversed(available_skills))
            available_skills.sort(key=lambda x: x.power)

            if available_skills:
                return available_skills[0]
            return None

        else:
            available_skills.sort(key=lambda x: (-x.current_pp, x.max_cd))
            if available_skills:
                return available_skills[0]
            else:
                return None


class ManipulatorHunter(Hunter):
    def choose_skill(
        self, available_skills: List[Skill], enemy_pokemon: Pokemon
    ) -> Optional[Skill]:
        # TODO

        heal_skill = list(filter(lambda x: x.skill_type == "Heal", available_skills))
        if self.pokemon.hp < self.pokemon.max_hp // 2 and heal_skill:
            heal_skill.sort(key=lambda x: x.power, reverse=True)
            return heal_skill[0]
        else:
            offensive_skills = list(
                filter(
                    lambda x: x.skill_type == "Attack" or x.skill_type == "Pierce",
                    available_skills,
                )
            )
            if not offensive_skills:
                offensive_skills = available_skills

            offensive_skills.sort(key=lambda x: x.power * x.current_pp, reverse=True)

            if offensive_skills:
                return offensive_skills[0]
            else:
                return None


class ConjurerHunter(Hunter):
    def choose_skill(
        self, available_skills: List[Skill], enemy_pokemon: Pokemon
    ) -> Optional[Skill]:
        # TODO
        heal_skill = list(filter(lambda x: x.skill_type == "Heal", available_skills))

        if self.pokemon.hp < self.pokemon.max_hp and heal_skill:
            heal_skill.sort(key=lambda x: x.power, reverse=True)
            return heal_skill[0]
        else:
            offensive_skills = list(
                filter(
                    lambda x: x.skill_type == "Attack" or x.skill_type == "Pierce",
                    available_skills,
                )
            )
            if not offensive_skills:
                offensive_skills = available_skills

            offensive_skills.sort(key=lambda x: (x.max_cd, -x.power))

            if offensive_skills:
                return offensive_skills[0]
            else:
                return None


class SpecialistHunter(Hunter):
    def choose_skill(
        self, available_skills: List[Skill], enemy_pokemon: Pokemon
    ) -> Optional[Skill]:
        if self.turn_count % 3 == 0:
            available_skills.sort(key=lambda x: (-1 * x.max_cd, -1 * x.power))
            if available_skills:
                return available_skills[0]
            else:
                return None
        else:
            available_skills.sort(key=lambda x: (x.current_pp, -1 * x.power))
            if available_skills:
                return available_skills[0]
            else:
                return None


class BattleArena:
    def __init__(self, hunter1: Hunter, hunter2: Hunter, max_turns: int):
        # TODO
        self.hunter1 = hunter1
        self.hunter2 = hunter2
        self.max_turns = max_turns

    def run(self) -> str:
        for turn in range(1, self.max_turns + 1):
            if not self.hunter1.pokemon.is_alive or not self.hunter2.pokemon.is_alive:
                break

            if turn % 2 == 0:
                for skill in self.hunter2.pokemon.skills:
                    skill.next_tick()
                self.hunter2.take_turn(self.hunter1)
            else:
                for skill in self.hunter1.pokemon.skills:
                    skill.next_tick()
                self.hunter1.take_turn(self.hunter2)

        if self.hunter1.pokemon.hp > self.hunter2.pokemon.hp:
            return self.hunter1.name
        elif self.hunter2.pokemon.hp > self.hunter1.pokemon.hp:
            return self.hunter2.name
        else:
            return "Draw"


def parse_hunter(input_fn) -> Hunter:
    h_name, nen_type = input_fn().split()
    p_line = input_fn().split()
    p_name, p_type = p_line[0], p_line[1]
    max_hp, atk, defense, num_skills = map(int, p_line[2:])
    skills = [Skill.from_string(input_fn()) for _ in range(num_skills)]
    pokemon = Pokemon.create(p_type, p_name, max_hp, atk, defense, skills)
    return Hunter.create(nen_type, h_name, pokemon)


if __name__ == "__main__":
    input_fn = sys.stdin.readline
    max_turns = int(input_fn().strip())
    h1 = parse_hunter(input_fn)
    h2 = parse_hunter(input_fn)

    arena = BattleArena(h1, h2, max_turns)
    winner = arena.run()

    print(f"{h1.name} ({h1.pokemon.name}): {h1.pokemon.hp}/{h1.pokemon.max_hp}")
    print(f"{h2.name} ({h2.pokemon.name}): {h2.pokemon.hp}/{h2.pokemon.max_hp}")
    print(f"Winner: {winner}")
