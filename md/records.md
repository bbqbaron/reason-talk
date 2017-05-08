# Records

Are like JS objects but...

* have a static type
* are immutable by default

---
## Preface: Type declarations

Like many modern FP-flavored langs, you can declare types in a way that looks like a value. 

```ocaml
type someThing = int;
```

---

This just declares that there is a type `someThing` that you can demand a value have, in a function definition, or anywhere. In this case, it's exactly the same as an `int`.

---

## Record Types
```ocaml
type characterClass = {
  hitDice: int,
  attackBonusPerLevel: float 
};

let aClass = {
  hitDice: 8,
  attackBonusPerLevel: 0.75
}
```

---

Records act a lot like JS objects. You can:

---

#### Pun
```ocaml
let hitDice = 12;
let barbarian = {
  hitDice, attackBonusPerLevel: 1.0
};
```

---

#### Destructure
```ocaml
let getHitDice { hitDice } => hitDice;
```

---

#### Spread
```ocaml
let withAttackBonus2 charClass => {
  ...charClass, attackBonusPerLevel: 2.0,
};
```

---

### Mutation
```ocaml
type counter = {
  mutable value: int
};

let counter = {
  value: 0
};

counter.value = counter.value + 1;
```