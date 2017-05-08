# Modules

Your files are not just collections of text, but objects in their own right. This is implicit in most module systems, but given more first-class support in Reason.

In particular:
* you can declare modules outright in code
* modules can have type signatures, and even arguments!

---
```ocaml
type roll = Roll int die;

module Rules = {
  let checkDie = Roll 2 D6;
};
```
---
## Signatures

You can declare type signature for a module, for all the usual reasons:
* guiding design decisions
* insulating implementations details

```ocaml
type size = Sm | Med | Lg;
module type Entity = {
  type t;
  let getSize: t => size;
};
```

---
## Aaaaand implement
```ocaml
module Character: Entity = {
  type t = {
    size: size
  };
  let getSize { size } => size; 
};
```
---
## Functors
...is kind of a weird term. Basically, you can 
define functions that produce modules.

---
## Why?
I'm kind of a typeclasses (Haskell) guy, so I admit I'm not sure why this system works the way it does. However! Let's demonstrate some beneficial uses:

---
```ocaml
module EntityCard = fun (Thing: Entity) => {
  type t = Thing.t;
  let showSize t => switch (Thing.getSize t) {
  | Sm => "Small"
  | Med => "Medium"
  | Lg => "Large"
  };
};
```