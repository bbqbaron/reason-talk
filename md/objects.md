# Objects

Objects are like records that can have methods (aka functions with a `this` reference) and visibility constraints. They combine some features of traditional classes and interfaces.

---

## An Object Type
```ocaml
type snack = Cheetos|Hummus;

type player = {
  .
  name: string,
  snack: snack
};
```

---

```ocaml
let p = {
  pub name = "foo";
  pub snack = Cheetos; 
  /* haha "pub snack" */
};
```

Fun trivia: You get a warning that `p` doesn't use its `this`. I.e., why is it an object and not a record?

---

### Open and closed 

```ocaml
type player = {
  .
  /* ... */
```
The `.` is a slightly weird way of specifying that this object type is "closed". That is, something that is `player` _may not contain_ other data. It has `name` and `snack`.

---

An "open" object has a `..` for some reason. This means that it may expose other fields, but it must take a type to "hold" them. It can in this way be a little bit like an interface.

```ocaml
type named 'a = {
  ..
  name: string
} as 'a;
```

---

```ocaml
let p:(named player) = {
  pub name = "foo";
  pub snack = Cheetos; 
  /* haha "pub snack" */
};
```

