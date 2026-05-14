---
layout: essay
type: essay
title: "Effort Estimation is Essential"
# All dates must be YYYY-MM-DD format!
date: 2026-05-03
published: true
labels:
  - GitHub
  - Software Engineering
---

<img width="200px" class="rounded float-start pe-4" src="../img/gith.png">

## How I Made My Effort Estimates
 
Within my final project, I did not spend a large amount of time on effort estimation. Each estimation took no longer than a minute, but that was a deliberate choice rather than a careless one. I knew what I was capable of, had enough buffer time to go out of bounds by a good amount, and would have rather spent the time working on the actual project implementation. The reason I could estimate quickly was because of how we structured our issues. I made sure each issue was broken down into small, clearly scoped pieces rather than broad items. For example, I would not create a single issue like "Account Management" when there are many parts beneath the surface: password hashes, admin functions, username mapping, each of which should be its own issue. When issues are scoped broadly, accurate estimation becomes nearly impossible. When they are scoped narrowly, estimation becomes straightforward.
 
I had no formal historical data to draw from, but I did rely on experience from similar exercises done in class. For instance, we had an issue for M1: add template page mockup. I estimated this at 30 minutes because we had done similar exercises using Bootstrap, Next.js, and PostgreSQL in class, and I had a good sense of how long those took. That estimate turned out to be slightly generous, as I had finished in about 20 minutes.


## The Benefits of Estimating in Advance
 
Even when estimates were off, the process of estimating still provided clear benefits. By providing estimates up front, we were able to distribute the workload across our four team members in a way that felt fair and manageable. With roughly 10 issues per milestone split among four people, knowing the rough time commitment for each issue helped us decide who would take on what.
 
The estimates also helped us identify when we were being too unambitious. I had originally stated that tag functionality would be a future addition, but when we reached milestone 2, the actual tracked effort showed that there was less work remaining than expected. That realization pushed us to bring tag functionality and other refinements into scope before the project deadline, rather than leaving them for later.

## Tracking Actual Effort
 
Tracking actual effort turned out to be genuinely useful. We used the GitHub Projects spreadsheet view to record both estimated and actual time for each issue. Every team member logged their actual time after completing an issue in the same place where the estimate lived, making it easy to compare the two side by side.
 
This comparison helped in a few ways. In some cases, estimates were close: The add template page mockup was estimated at 30 minutes and took 20. In other cases, the gap was more significant. I had estimated 30 minutes to refine the add template page from its mockup state to its final version, but it ended up taking around 50 minutes because I kept iterating on the design and was not satisfied with early attempts. That kind of gap is useful to notice, because it highlights that tasks involving subjective judgment and visual refinement tend to take longer than tasks with clear, defined endpoints. Across the board, some estimates were overstated and some were understated, but we did not have any extreme outliers, which suggests our estimation approach was reasonable even if not perfectly precise.
 
As for accuracy of our tracking, I believe it was fairly reliable. Since we logged time in GitHub Projects right after completing each issue, the numbers were fresh. It was not perfectly precise down to the minute, but it was close enough to be useful for planning the next milestone.

## How We Tracked
 
We tracked effort by letting each member estimate for their own issues within GitHub Projects. We believed that each person is best positioned to accurately estimate their own work. If I were to estimate for another member, it might come across as expecting too much of them or giving them too little. By letting each member estimate for themselves, we distributed workload fairly and not just equally.

## Reflection
 
Looking back, the main thing I would change is breaking issues down even further. Some issues in our project, like "Create Password Hash," were completely new to all of us, and we did not have a good basis for estimating them. Next time, I would research unfamiliar processes ahead of time and outline the steps involved so that the estimation can be better informed. The home page refinement issue also taught me that tasks involving iteration and subjective design decisions need more generous estimates than tasks with clear-cut implementation goals. I would account for that in future projects.

I would also try to be more consistent about logging actual time immediately after finishing an issue. On a few occasions, the time was logged from memory after a short delay, which likely reduced accuracy slightly.

## AI Use
 
No AI tools were used for effort estimation or tracking. All estimates and actual time logging were done manually through GitHub Projects. I did use Claude Code for implementation tasks within the project, and knowing I had that available led me to take on slightly larger issues and estimate shorter times than I would have otherwise, but the estimation and tracking process itself was entirely manual.
