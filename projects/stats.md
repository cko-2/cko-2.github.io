---
layout: project
type: project
image: img/lean.png
title: "Probability and Statistics Demonstration"
date: 2025
published: true
labels:
  - Wolfram Mathematica 
  - Probability and Statistics
  - Lean
summary: "Implemented probability and statistics textbook demonstration program in Lean."
---
During my Elementary Probability and Statistics class, we had an optional project that involved taking one of the textbook programs and writing it in Lean. Since the original program was written in Mathematica, it required a lot of research into both Lean and Mathematica. 

For this project, I worked alone to implement the function, as well as make sure it performed exactly like the original program. Since the program operated mainly on fixed values, the main challenge was adhering to the Lean syntax and transcribing the Mathematica program. 

Because both Lean and Mathematica were new to me, I learned a lot about being able to adapt to new languages quickly and perform the necessary research needed to have both of these programs run as intended. In the future, I can be expected to learn and adapt quickly to languages that I have little to know experience with, using my foundational coding knowledge. Below is the Lean implementation of a horse race probability simulation:

```cpp
import Init

def simulateRaces (n : Nat) : IO Unit := do
  let rec run (i : Nat) (acorn balky chestnut dolby : Nat) : IO Unit := do
    if i ≥ n then
      let total := n.toFloat
      IO.println ""
      IO.println s!"Acorn wins: {acorn}"
      IO.println s!"Acorn won {acorn.toFloat / total * 100} percent of the time."
      IO.println ""
      IO.println s!"Balky wins: {balky}"
      IO.println s!"Balky won {balky.toFloat / total * 100} percent of the time."
      IO.println ""
      IO.println s!"Chestnut wins: {chestnut}"
      IO.println s!"Chestnut won {chestnut.toFloat / total * 100} percent of the time."
      IO.println ""
      IO.println s!"Dolby wins: {dolby}"
      IO.println s!"Dolby won {dolby.toFloat / total * 100} percent of the time."
      pure ()
    else
      let randNat ← IO.rand 0 999
      let x : Float := randNat.toFloat / 1000.0
      let (newAcorn, newBalky, newChestnut, newDolby) :=
        if x < 0.3 then
          (acorn + 1, balky, chestnut, dolby)
        else if x < 0.7 then
          (acorn, balky + 1, chestnut, dolby)
        else if x < 0.9 then
          (acorn, balky, chestnut + 1, dolby)
        else
          (acorn, balky, chestnut, dolby + 1)
      run (i + 1) newAcorn newBalky newChestnut newDolby

  run 0 0 0 0 0

-- Change the number here to run more or fewer races
#eval simulateRaces 10000
```

These implementations were published on my professor's [Github page](https://github.com/bjoernkjoshanssen/hypothesis/tree/main/Hypothesis).
