---
layout: essay
type: essay
title: "Final Project Proposal"
date: 2026-11-04
labels:
  - Software Engineering
  - Nextjs
---

<img width="200px" class="rounded float-start pe-4" src="../img/proj.png">

# Project: UH ITS Email Helper
Names of proposers: Chase Obuhanych

## Overview
The Problem: UH ITS Help Desk student employees respond to countless emails every day, however, typing these emails takes a lot of time and effort to ensure accuracy and professionalism. While TeamDynamix has a feature for email templates that allow you to respond to common issues and concerns with a few clicks, these do not encompass most of the common issues that users experience. While you can also create your own templates in TeamDynamix, students are limited to 20 hours of work per week; their personal library of templates will be small, inconvenient to manage, and possibly provide inaccurate solutions.

The Solution: UH ITS Email Helper provides a database of shared email templates created by the student employees. With a shared library of templates, student employees are able to use other's templates, provide feedback and suggestions, and upload their own templates to the database.

## Approach
The goal of this webapp would be to provide UH ITS student employees a way to boost their productivity and reduce the mental fatigue from typing the same email multiple times to different users. Student employees will log into the webapp, and be able to create, update, and delete their own database entries. They will also be able to read and comment on all other entries. Database entries will consist of a description of the problem, category, and the email body. 

When looking for an entry, they will be grouped in categories with a description of the problem as the title. When clicking on the title, it will lead to a page where they would be able to view and copy the email template, or add a comment to it. This will allow student employees to effectively respond to tickets with a few clicks instead of drafting and revising a professional email for common issues.


## Mockup page ideas

* Log in page
* Home page
* Template listing page
* Adding template page
* View and use template page

## Use case ideas

Student employee logs into the webapp:
1. After responding to a TDX ticket regarding a common issue, they may click 'Add' and upload their response as a template to the database.
2. Upon viewing a new TDX ticket, they search for the corresponding database entry in the webapp, click on it, and copy the email response.

## Beyond the basics

After implementing the database functions, we can elevate this by making it even more efficient for ITS student employees to find the template they need. Adding a 'Tags' column to each database entry would allow for a search alorithm that would let users search for the template they need without needing to skim over each entry in the category.
