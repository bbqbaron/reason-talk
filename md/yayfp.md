## Interlude: Why functional?

"Functional" is more of a cluster of language design choices than a strict objective test, but you should learn at least one FP lang! The stricter the better, to understand the paradigm.

---

### Sweet perks

You may have seen a million versions of this slide in the world, but here are some helpful parts of FP style. It's cool how it fits together:

* If you can't mutate references, then...
  * You have to use return values
    * So now you can refactor with no hassle
---
  * You can't cause an in-memory race condition
    * You can parallelize your code more easily 
---
  * The inability to hand-maintain mutable state
    * makes your iteration a lot less tangled
    * makes you realize how often the same pattern is used over and over as if it's new each time
