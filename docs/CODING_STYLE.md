## Names
Should include unit in the name if there is one.

```c
// For example...
uint64_t time_msecs;
uint64_t weight_kg;

void get_weight_kg(char *prompt);
```

### Function Names
Function names should:
* use all lower case letters
* use `_` as the word separator

A function should only do one thing.

Suffixes and prefixes are sometimes useful:

* Suffixes:
    * max - to mean the maximum value something can have.
    * cnt - the current count of a funning count variable.
    * key - key value.
* Prefixes:
    * is - to ask a question about something. Whenever someone sees: `is` they know it's a question.
    * get - get a value.
    * set - set a value.

