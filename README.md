# CalculationEngine

## Overview

CalcuationEngine supports the following two components
 
- Multiplier
- Divider

Multiplier is a calculator of the multiplication. It takes only integer as an input data. You can check a calculated result from stdout.Divider calculates the division. As an input data, integers and files are allowed. The calculated results are displayed in stdout.

Please refer to https://github.com/joohyung-jo/calculator/blob/main/doc/TechnicalReference_CalculatorEngines.pdf for more details

## How to run

The program, calc provides command line execution for CalculationEngine. This chapter describes how to run this program. Basic command is mentioned below

```
$ calc <engine_name> <list of integer> or <file_list>
```

All file names have an implicit “.txt” on the end. So please enter only file name except “.txt”

### Multiplier

Multiplier allows only file name for the input data. For instance, you can execute Multiplier like mentioned below.

```
bin$ ./calc Multiplier input1
*2*4*6*4*3*10*100*20*50
576000000
```

### Divider

Divider allows file name and integer value. For instance, you can execute Divider with mixed input data like mentioned below. In this case, Divider takes input1.txt and 4 as the input data.

```
bin$ ./calc Divider input1 4
2/4=0.5
6/4=1.5
3/10=0.3
100/20=5
50/4=12.5
```

### Unit Test

You can execute the unit test in the command line like mentioned below. You can find the procedure of each unit test and the final result from stdout.

```
bin$ ./calc UnitTest
 ########################################
 ###        TEST_DIVIDER_001          ###
 ########################################
 [Test Step 001] Input a value : -2147483648
 [Pass Criteria 001-1] Check the size of input storage---> PASS
 [Pass Criteria 001-2] Check the out value if it is equal to min value---> PASS
 [snip]
```
 