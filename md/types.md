# Types

One of the strengths of ML-family languages like Reason, Ocaml, Haskell, PureScript, and Elm is that they allow us to express types in ways that are either more verbose or outright impossible in other languages. They're a really useful modeling tool.

---

## Type constructors
Types are often identified by a "constructor" or "tag" that lets the compiler figure out what type you're talking about. The syntax is fortunately quite elegant.

---

```ocaml
type Game = DungeonsAndDragons 
```

There is now a type `Game` in your system with only one possible value: the arbitrary tag `DungeonsAndDragons`. This tag has no inherent value or functionality; it's just an identifier.

---

## Variant Types
That is, types that can be one of two completely different types. Each case is given a "constructor" or "tag" that identifies it.

---

```ocaml
type Die = D4|D6|D8|D10|D12|D20
```

This is a lot like the more OO "enum", without the underlying artifacts like having an associated int value, etc.

## Tag Arguments 

Tags can take values! This lets you build variant types that hold completely different information.

---

```ocaml
type maybe = Some int | Nothing; 
```

So now you can say `let a = Some int;` and it is a valid value of type `maybe`. Of course, it being hard-coded to `int` is kind of annoying, unless you're a Go programmer, in which case it's just life.

---

## Type Arguments

You can reuse type definitions!

---

```ocaml
type maybe 'a = Some 'a | Nothing;
```

This is how you might simulate `null`.

---

```ocaml
type result 'a = Ok 'a | Err string;
type either 'a 'b = Left 'a | Right 'a;
```

I miss type systems like this every second of writing code that doesn't have them! I can't recommend strongly enough that you try them out.


