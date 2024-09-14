# CP Standard Libs
 
## TODO
- [ ] Add core library:
    - [X] File I/O
    - [ ] Time
    - [X] Graphics
    - [ ] Keyboard
    - [ ] Mouse
    - [ ] Sound
    - [X] Exception
    - [X] Console:
        - [X] Set caret position
        - [X] Change color
        - [X] Set font
    - [ ] Web/API
- [ ] Add CP library:
    - [X] Strings
        - [X] size: size of string
        - [X] contains: string is contained in other string
        - [X] ends_with, starts_with: string is contained in extremities
        - [X] substring: returns substring
        - [X] replace: replace substring for another
        - [X] to_lower, to_upper
        - [X] to_string: value to string
        - [X] split: split string in array
        - [X] join: merge array values in string
        - [X] left_trim, right_trim, trim: removes whitespaces strings
    - [X] Arrays
        - [X] size: size of array
        - [X] contains: value is contained in array
        - [X] sorted: sort a list
        - [X] reverse: reverse a list
    - [X] Math
        - [X] abs: ret absolute value of a number
        - [X] max: return greather from two or more parameters
        - [X] min: return lesser from two or more parameters
        - [X] sum: sum all items from array
        - [X] round: round a float number
        - [X] hash: returns hash of string
    - [X] Random (https://docs.godotengine.org/en/stable/classes/class_randomnumbergenerator.html):
        - [X] randi(from: int, to: int): int
        - [X] seed(seed: int)
        - [X] ...
    - [ ] Collections [null (<- first ->) , (<- item2 ->) , (<- item3 ->) , (<- last ->) null]
        - [X] Collection
            - [X] _default_add: adds end
            - [X] _default_get: gets end
            - [X] _default_remove: removes end
            - [X] create: create new collection
            - [X] create: from array
            - [X] clear: delete all items
            - [X] is_empty: check if is empty
            - [X] to_array: converts to array
        - [X] List
            - [X] add: _default_add
            - [X] insert: insert index
            - [X] remove: _default_remove
            - [X] delete: delete index
            - [X] get: get index
        - [X] Queue
            - [X] enqueue: _default_add
            - [X] dequeue: removes from start
            - [X] front: gets fisrt
            - [X] back: _default_get
        - [X] Stack
            - [X] push: _default_add
            - [X] pop: _default_remove
            - [X] peek: _default_get
        - [ ] Dict
            - [X] struct to dict
            - [X] dict to json string
            - [X] json_stringfy
            - [ ] json_parse
    - [X] Util:
        - [X] isnumber
        - [X] istext
