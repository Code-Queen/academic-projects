### Copy and Move Semantics

Processing file with constructor, copy assignment, copy constructor, move assignment and move constructor + timimg

Example output:
```
...
Line 124452 --- > <---
Line 124453 --- >End of this Etext of The Complete Works of William Shakespeare <---
Line 124454 --- > <---
Line 124455 --- > <---
Line 124456 --- > <---
Constructor      1.162 seconds - b.size = 124456
copy operator=
Copy Assignment  0.012 seconds - a.size = 124456
move operator=
Move Assignment  0.009 seconds - b.size = 0
 - a.size = 124456
copy constractor
copy operator=
Copy Constructor 0.010 seconds - c.size = 124456
move constractor
Move Constructor 0.000 seconds - a.size = 0
 - d.size = 124456
~Text
~Text
~Text
~Text

```