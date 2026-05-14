---
layout: essay
type: essay
title: "Coding Standards: Clean Yet Frustrating"
# All dates must be YYYY-MM-DD format!
date: 2026-02-11
published: true
labels:
  - typescript
  - ESLint
---

<img width="200px" class="rounded float-start pe-4" src="../img/standards.png">

## A new extent of coding standards

Although I was aware of common coding standards in the past, I never realized the extent to which they could reach. Before this class, “coding standards” to me just meant not writing spaghetti code. Using ESLint with VSCode changed that definition entirely. ESLint does not just flag logic problems. It flags whitespace, trailing spaces, quote style, spacing around brackets, and dozens of other things I never thought twice about. Having to make sure your code is formatted in such a strict way, such that no errors appear in ESLint, initially feels like a waste of time. However, it goes without saying that these coding standards are extremely useful in certain scenarios, especially when multiple people are collaborating on a project. Incorporating these new, stricter coding standards turns a program from “I need to be able to understand my code” to “I need others to understand my code.”

## The first week with ESLint

My first week using ESLint was genuinely frustrating. Simple tasks that would normally take a few minutes started taking longer because I kept getting stopped by formatting errors before I could even test my code. A common example was trying to push changes, only to find out I had a trailing whitespace error somewhere, or that I had used double quotes where single quotes were expected. The errors themselves were not difficult to fix, but having them pile up on otherwise functional code made the whole process feel tedious. Here is the kind of thing that would stop me:

```
error  Strings must use singlequote  quotes
error  Trailing spaces not allowed    no-trailing-spaces
```

Neither of these errors means the code does not work. They are purely stylistic. At first, that felt pointless.

## Does ESLint help you learn the language?

ESLint did not teach me TypeScript directly. It did not explain why something worked or help me understand a new concept. What it did do was force me to be consistent. Over time, I stopped making the same formatting mistakes because fixing them repeatedly made the correct style feel automatic. It is like wearing a back brace to correct your posture. It is uncomfortable and you are aware of it constantly, but it is quietly correcting habits you did not even know were bad. You probably will not notice the improvement while it is happening, but the habits form regardless.

I think coding standards have the potential to help developers write cleaner code in a language over time, but not in the way a tutorial or a textbook would. It is more passive than that.

## The end of distinctive coding

Without coding standards, people tend to code in whatever style feels comfortable to them. For example, I usually do not put spaces in certain areas where others might because it looks better to me, and helps me read my own code better. With these stricter coding standards, there is little to no agency in coding style. While you may no longer be able to tell who wrote the code, this is considered to be a good thing, as having a consistent style among multiple people will greatly increase everyone’s ability to read the code. It is like having multiple dialects across one language: if everyone learned and used the common dialect, communication would become much easier. While it may be annoying and tedious to adhere to these stricter coding standards at first, it will ultimately benefit all collaborators in the long run.

## The option to ignore coding standards

Although in most cases it would be beneficial to adhere to these coding standards, sometimes you may be able to ignore them. For example, if I was working on a project alone, in which I just needed my program to fulfill a small purpose such as automating a simple task, I may not need these coding standards. As long as I write code that is easily decipherable to me personally, there is not much reason to be hunting the red underlines that appear with ESLint. Ultimately, the functionality of the code should be the priority in simple tasks, and spending a lot more time to improve readability on code that you will never see again is pointless.

## Conclusion

Coding standards are a trade-off. You give up some personal style and freedom in exchange for code that a whole team can read and maintain. That trade-off is worth it when working collaboratively, and less necessary when working alone. The first week with ESLint was the most frustrating part of this class for me, but by the end of the group project, I was writing cleaner code without thinking about it. Whether ESLint teaches you a language is debatable, but it does correct your habits over time, just not in an obvious way.

