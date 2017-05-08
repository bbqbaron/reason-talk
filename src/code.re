let add a b => a + b;

let inc = add 1;

let pipe f1 f2 =>
  fun arg =>
    arg
      |> f1
      |> f2;

type someThing = int;
let a = if true {
  1
} else 2;

let makeEven n =>
  if (n mod 2 == 0) {
    n
  } else inc n;

let makeEvenSwitch n => switch (n mod 2) {
  | 0 => n
  | _ => inc n
};

let sayhi () => print_string "hi!";

let _ = {
  let b = 1;
  let c = 2;
  b + c
};

let list = [1,2,3];

let head l => switch l {
  | [] => None 
  | [x] => Some x
  | [x, ..._] => Some x
};

switch (head list) {
  | Some h => h
  | None => 0
};

type myRec = {
  foo: int, bar: string
};

let myRec = {
  foo: 1,
  bar: "bar" 
};

let myTuple = (1, "hi");

type die = D4 | D6 | D8 | D10 | D12;
type char = Fighter | Wizard | Cleric | Thief; 

let char = Fighter; 

let hd char => switch char {
| Fighter => D10
| Wizard => D4
| Cleric => D8
| Thief => D6 
};

module type CharClass = {
  let hd: die;
};

module Fighter: CharClass = {
  let hd = D10;
};

type characterClass = {
  hitDice: int,
  attackBonusPerLevel: float 
};

let aClass = {
  hitDice: 8,
  attackBonusPerLevel: 0.75
};
let hitDice = 12;
let barbarian = {
  hitDice, attackBonusPerLevel: 1.0
}; 

let getHitDice { hitDice } => hitDice;
type person = {
  name: string,
  mutable age: int
};
let me = {name: "Jordan", age: 30};
me.age = me.age + 1; /* alter `me`. Happy birthday! */
type counter = {
  mutable value: int
};

let counter = {
  value: 0
};

counter.value = counter.value + 1;

type m 'a = Some 'a | Nothing;

let firstInList list => /* aka head */
  switch list {
  | [] => Nothing
  | [x] => Some x
  | [x, ..._] => Some x
};


let sidesOfDie die => switch die {
| D4 => 4
| D6 => 6
| D8 => 8
| D10 => 10
| D12 => 12
};

let mapOver fn maybe => switch maybe {
| Some x => fn x;
| Nothing => Nothing
};

type snack = Cheetos|Hummus;

type player = {
  .
  name: string,
  snack: snack
};

type named 'a = {
  ..
  name: string
} as 'a;

let p:(named player) = {
  pub name = "foo";
  pub snack = Cheetos; 
  /* haha "pub snack" */
};