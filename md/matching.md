# Matching

Pattern-matching overlaps with destructuring, which you'll recognize from JS like:

---

```javascript
let [a, ...rest] = [1,2,3];
const getFoo = ({ foo }) => foo;
```

---

Reason and its cousins provide something like the C-style `switch` construct, but more powerful. It's basically a big if-equals-else block, but:

---

* it can perform variable binding in your cases
* is checked for exhaustiveness so you don't miss one
* doesn't fall through if you forget `break`!
* is an _expression_ so it seamlessly returns things

---

```ocaml
let firstInList list => /* aka head */
  switch list {
  | [] => Nothing
  | [x] => Some x
  | [x, ..._] => Some x
  };
```

---

```ocaml
let sidesOfDie die => switch die {
| D4 => 4
| D6 => 6
| D8 => 8
| D10 => 10
| D12 => 12
};
```

---

```ocaml
let mapOver fn maybe => switch maybe {
| Some x => fn x;
| Nothing => Nothing
};
```