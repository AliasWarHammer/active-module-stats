# Active Module Statistics - Design and Code Document

## Problem statement

Display the device driver/module statistics currently active in the Operating system.

## Solution

On closer inspection of the ```modules``` file in ```/proc```, we note that the following details are specified.
- name
- size
- instances
- dependencies
- status
- offset

Apart from the above details, we run the command line utility, ```modinfo``` on each of the modules to obtain more details. 
- filename
- license
- description
- author(s)
- srcversion
- vermagic
- sig_key
- sig_hashalgo
- parm(s)

Note: This list is non-exhaustive and depends on the module.

The outputs of the two above mentioned utilities are concatenated and output for each of the active modules. 
Active modules are determined by the number of instances currently running. 

## Data Structures

## Functions

## Specifications

- Operating System: 18.04.1-Ubuntu (Linux version 5.0.0-29-generic)
- Processor(s): Intel® Core™ i5-7200U CPU @ 2.50GHz × 4
