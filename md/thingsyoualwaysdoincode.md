# Things you always do in code, Reason edition
## AKA the Rosetta Stone
---
### Assign
```ocaml
let a = 1;
```
---
#### ...nested!
```ocaml
let a = {
  let b = 1;
  b + 1
};
/* a == 2 */
```
---
### Print
```ocaml
print_string "hi!";
let name = "Elminster";
print_string "hi, " ^ name;
```
---
### Conditional
```ocaml
let a = if true {
  1
} else 2;

let b = true ? 1 : 2;
```
---
### Functions
```ocaml
let add a b => a + b;
let doSideEffects () => print_string "hi!";
```
---
#### ...with curry!
"Currying" is the automatic creation of new functions from functions that you haven't given all the arguments to.

It's a great way to make your logic simple and composable, and specialize functions by giving them part of their arguments.

---
```ocaml
let increment = add 1;
let two = increment 1;
let three = increment 2;
```
#### curry is awesome
---
#### ...and pipes!
Pipes just allow you to look at a series of operations as a rightward-flowing chain. I find it super readable.
```ocaml
let a = 1
  |> increment
  |> add 5
  |> increment
```

