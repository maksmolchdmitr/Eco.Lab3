# Quick start

```
bash start_and_build_project.sh
```

# Example of using:

<pre>
ShellSort logging with various stepping:

1) ShellStep:
Example with int array logging:
Array: [ 8 7 6 5 4 3 2 1 ]
Swap for 8 and 4
Array was been changed! Current array state: Array: [ 4 7 6 5 8 3 2 1 ]
Swap for 7 and 3
Array was been changed! Current array state: Array: [ 4 3 6 5 8 7 2 1 ]
Swap for 6 and 2
Array was been changed! Current array state: Array: [ 4 3 2 5 8 7 6 1 ]
Swap for 5 and 1
Array was been changed! Current array state: Array: [ 4 3 2 1 8 7 6 5 ]
Swap for 4 and 2
Array was been changed! Current array state: Array: [ 2 3 4 1 8 7 6 5 ]
Swap for 3 and 1
Array was been changed! Current array state: Array: [ 2 1 4 3 8 7 6 5 ]
Swap for 8 and 6
Array was been changed! Current array state: Array: [ 2 1 4 3 6 7 8 5 ]
Swap for 7 and 5
Array was been changed! Current array state: Array: [ 2 1 4 3 6 5 8 7 ]
Swap for 2 and 1
Array was been changed! Current array state: Array: [ 1 2 4 3 6 5 8 7 ]
Swap for 4 and 3
Array was been changed! Current array state: Array: [ 1 2 3 4 6 5 8 7 ]
Swap for 6 and 5
Array was been changed! Current array state: Array: [ 1 2 3 4 5 6 8 7 ]
Swap for 8 and 7
Array was been changed! Current array state: Array: [ 1 2 3 4 5 6 7 8 ]
Example with string array logging:
Array: [ 'Algo' 'Operation' 'C' 'C++' ]
Swap for Algo and C
Array was been changed! Current array state: Array: [ 'C' 'Operation' 'Algo' 'C++' ]
Swap for Operation and C++
Array was been changed! Current array state: Array: [ 'C' 'C++' 'Algo' 'Operation' ]

2) HibbardStep:
Example with int array logging:
Array: [ 1 2 3 4 5 6 7 8 ]
Swap for 8 and 1
Array was been changed! Current array state: Array: [ 1 7 6 5 4 3 2 8 ]
Swap for 7 and 4
Array was been changed! Current array state: Array: [ 1 4 6 5 7 3 2 8 ]
Swap for 6 and 3
Array was been changed! Current array state: Array: [ 1 4 3 5 7 6 2 8 ]
Swap for 5 and 2
Array was been changed! Current array state: Array: [ 1 4 3 2 7 6 5 8 ]
Swap for 4 and 3
Array was been changed! Current array state: Array: [ 1 3 4 2 7 6 5 8 ]
Swap for 4 and 2
Array was been changed! Current array state: Array: [ 1 3 2 4 7 6 5 8 ]
Swap for 3 and 2
Array was been changed! Current array state: Array: [ 1 2 3 4 7 6 5 8 ]
Swap for 7 and 6
Array was been changed! Current array state: Array: [ 1 2 3 4 6 7 5 8 ]
Swap for 7 and 5
Array was been changed! Current array state: Array: [ 1 2 3 4 6 5 7 8 ]
Swap for 6 and 5
Array was been changed! Current array state: Array: [ 1 2 3 4 5 6 7 8 ]
Example with string array logging:
Array: [ 'C' 'C++' 'Algo' 'Operation' ]
Swap for Algo and C++
Array was been changed! Current array state: Array: [ 'C++' 'Operation' 'C' 'Algo' ]
Swap for Operation and C
Array was been changed! Current array state: Array: [ 'C++' 'C' 'Operation' 'Algo' ]
Swap for C++ and C
Array was been changed! Current array state: Array: [ 'C' 'C++' 'Operation' 'Algo' ]
Swap for Operation and Algo
Array was been changed! Current array state: Array: [ 'C' 'C++' 'Algo' 'Operation' ]

3) KnuthStep:
Example with int array logging:
Array: [ 1 2 3 4 5 6 7 8 ]
Swap for 8 and 7
Array was been changed! Current array state: Array: [ 7 8 6 5 4 3 2 1 ]
Swap for 8 and 6
Array was been changed! Current array state: Array: [ 7 6 8 5 4 3 2 1 ]
Swap for 7 and 6
Array was been changed! Current array state: Array: [ 6 7 8 5 4 3 2 1 ]
Swap for 8 and 5
Array was been changed! Current array state: Array: [ 6 7 5 8 4 3 2 1 ]
Swap for 7 and 5
Array was been changed! Current array state: Array: [ 6 5 7 8 4 3 2 1 ]
Swap for 6 and 5
Array was been changed! Current array state: Array: [ 5 6 7 8 4 3 2 1 ]
Swap for 8 and 4
Array was been changed! Current array state: Array: [ 5 6 7 4 8 3 2 1 ]
Swap for 7 and 4
Array was been changed! Current array state: Array: [ 5 6 4 7 8 3 2 1 ]
Swap for 6 and 4
Array was been changed! Current array state: Array: [ 5 4 6 7 8 3 2 1 ]
Swap for 5 and 4
Array was been changed! Current array state: Array: [ 4 5 6 7 8 3 2 1 ]
Swap for 8 and 3
Array was been changed! Current array state: Array: [ 4 5 6 7 3 8 2 1 ]
Swap for 7 and 3
Array was been changed! Current array state: Array: [ 4 5 6 3 7 8 2 1 ]
Swap for 6 and 3
Array was been changed! Current array state: Array: [ 4 5 3 6 7 8 2 1 ]
Swap for 5 and 3
Array was been changed! Current array state: Array: [ 4 3 5 6 7 8 2 1 ]
Swap for 4 and 3
Array was been changed! Current array state: Array: [ 3 4 5 6 7 8 2 1 ]
Swap for 8 and 2
Array was been changed! Current array state: Array: [ 3 4 5 6 7 2 8 1 ]
Swap for 7 and 2
Array was been changed! Current array state: Array: [ 3 4 5 6 2 7 8 1 ]
Swap for 6 and 2
Array was been changed! Current array state: Array: [ 3 4 5 2 6 7 8 1 ]
Swap for 5 and 2
Array was been changed! Current array state: Array: [ 3 4 2 5 6 7 8 1 ]
Swap for 4 and 2
Array was been changed! Current array state: Array: [ 3 2 4 5 6 7 8 1 ]
Swap for 3 and 2
Array was been changed! Current array state: Array: [ 2 3 4 5 6 7 8 1 ]
Swap for 8 and 1
Array was been changed! Current array state: Array: [ 2 3 4 5 6 7 1 8 ]
Swap for 7 and 1
Array was been changed! Current array state: Array: [ 2 3 4 5 6 1 7 8 ]
Swap for 6 and 1
Array was been changed! Current array state: Array: [ 2 3 4 5 1 6 7 8 ]
Swap for 5 and 1
Array was been changed! Current array state: Array: [ 2 3 4 1 5 6 7 8 ]
Swap for 4 and 1
Array was been changed! Current array state: Array: [ 2 3 1 4 5 6 7 8 ]
Swap for 3 and 1
Array was been changed! Current array state: Array: [ 2 1 3 4 5 6 7 8 ]
Swap for 2 and 1
Array was been changed! Current array state: Array: [ 1 2 3 4 5 6 7 8 ]
Example with string array logging:
Array: [ 'C' 'C++' 'Algo' 'Operation' ]

</pre>