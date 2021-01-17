# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).

tests = [    {'description': 'PINA; 0x00, PINB: 0x00, PINC: 0x00 -> PORTD: 0x00',
    'steps': [{'inputs': [('PINA', 0x00)], 'iterations': 5},
        {'inputs': [('PINB',0x00)], 'iterations':5},
        {'inputs': [('PINC',0x00)], 'iterations':5},

        ],
    'expected':[('PORTD',0x00)],
    },
    {'description': 'PINA: 81, PINB:0x0,pinC:0x0',
    'steps': [{'inputs': [('PINA', 81)], 'iterations': 5},
        {'inputs': [('PINB',0x0)], 'iterations':5},
        {'inputs': [('PINC',0x0)], 'iterations':5},

        ],
    'expected':[('PORTD',0x16)],
    },
    {'description': 'PINA: 40, PINB:40,pinC:40 -> PORTD: 0x1C',
    'steps': [{'inputs': [('PINA', 40)], 'iterations': 5},
        {'inputs': [('PINB',40)], 'iterations':5},
        {'inputs': [('PINC',40)], 'iterations':5},

        ],
    'expected':[('PORTD',0x1C)],
    },
    {'description': 'PINA: 100, PINB:100,pinC:100->PORTD 0x49',
    'steps': [{'inputs': [('PINA', 100)], 'iterations': 5},
        {'inputs': [('PINB',100)], 'iterations':5},
        {'inputs': [('PINC',100)], 'iterations':5},

        ],
    'expected':[('PORTD',0x49)],
    },
    {'description': 'PINA: 91, PINB:10,pinC:10->PORTD:0x1A',
    'steps': [{'inputs': [('PINA', 91)], 'iterations': 5},
        {'inputs': [('PINB',10)], 'iterations':5},
        {'inputs': [('PINC',10)], 'iterations':5},

        ],
    'expected':[('PORTD',0x1A)],
    },
    {'description': 'PINA: 10, PINB:10,pinC:91->PORTD:0x1A',
    'steps': [{'inputs': [('PINA', 10)], 'iterations': 5},
        {'inputs': [('PINB',10)], 'iterations':5},
        {'inputs': [('PINC',91)], 'iterations':5},

        ],
    'expected':[('PORTD',0x1A)],
    },
    {'description': 'PINA: 255, PINB:255,pinC:255->PORTD:0xBD',
    'steps': [{'inputs': [('PINA', 255)], 'iterations': 5},
        {'inputs': [('PINB',255)], 'iterations':5},
        {'inputs': [('PINC',255)], 'iterations':5},

        ],
    'expected':[('PORTD',0xBD)],
    },



]
#watch = ['PORTB']




# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint

