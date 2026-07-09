# objects

A one-hour experiment: building Java-flavored objects in plain C.

## Warnings
This README is written by CLAUDE OPUS 4.7

## The story

I took the written part of my C exam and made a mistake with `static` — I hadn't fully internalized what internal linkage really means or where it belongs. The oral is tomorrow (July 10), and instead of just re-reading the topic, I decided to nail it down by *using* it: could I take `static` (plus opaque structs, plus function pointers) and build Java-style encapsulation in C? Private field, public method, called on the object itself?

About an hour later — including time spent reading and asking around — this is what I had. The mental model is copied straight from Java's object model: one field I don't want anyone touching directly, two accessors that the outside world can only reach through the object, not as free-standing functions. Building it forced me to actually understand what I'd gotten wrong on the written exam, which was the point.

## Current state

- `persona.h` — public header. Right now it exposes only `create_person` and an opaque `Person` typedef.
- `Person.c` — defines `struct Person` with an `int age` plus two function pointers, and the `static` implementations they point to.
- `draft.c` — driver / `main` that calls `create_person(20)`.


## Not done, intentionally

- No Makefile. For now: `gcc draft.c Person.c -o test`.
- No further documentation.
- No tests, no inheritance, no vtable generalization. One class, one point.

## Breadcrumbs for future-me

The pattern isn't original. After I built it I learned it's essentially the idea behind GObject/GTK, CPython's `PyObject_HEAD`, and Chapter 1 of Axel Schreiner's *Object-Oriented Programming with ANSI-C* (1993, freely available online). Good reading if I ever come back to extend this.

The interesting technical wrinkle worth remembering: casting between the public and extended structs sits in the strict-aliasing gray zone. Practically fine on every real compiler; formally murky in the standard. If I want ironclad standard compliance, the escape hatch is a `union` that puts both structs in "common initial sequence" territory.
