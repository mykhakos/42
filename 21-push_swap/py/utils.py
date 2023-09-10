from copy import copy


class Sorter:
    def __init__(self, a: list[int], print: bool = False) -> None:
        """Initializes the Sorter with a given list.

        Args:
            a: A list of integers to be sorted.
        """
        self.a = a
        self.b: list[int] = []
        self.actions: int = 0
        self.print = print
    
    def _do_action(self, name: str):
        self.actions += 1
        if self.print:
            #print(name)
            #"""
            print(f'{self.actions}. {name}')
            print('-'*10)
            print(f'A: {" ".join(str(i) for i in self.a)}')
            print(f'B: {" ".join(str(i) for i in self.b)}')
            print()
            #"""


    def sa(self):
        """Swaps the first two elements at the top of stack a. 
        If there is only one or no elements, do nothing.
        """
        
        if len(self.a) >= 2:
            self.a[0], self.a[1] = self.a[1], self.a[0]
        self._do_action('sa')

    def sb(self):
        """Swaps the first two elements at the top of stack b.
        If there is only one or no elements, do nothing.
        """
        
        if len(self.b) >= 2:
            self.b[0], self.b[1] = self.b[1], self.b[0]
        self._do_action('sb')
        
    def ss(self):
        """Performs sa and sb at the same time."""
        
        if len(self.a) >= 2:
            self.a[0], self.a[1] = self.a[1], self.a[0]
        if len(self.b) >= 2:
            self.b[0], self.b[1] = self.b[1], self.b[0]
        self._do_action('ss')

    def pa(self):
        """Takes the first element at the top of b and puts it at the top of a.
        Does nothing if b is empty.
        """
        
        if self.b:
            self.a.insert(0, self.b.pop(0))
        self._do_action('pa')

    def pb(self):
        """Takes the first element at the top of a and puts it at the top of b.
        Does nothing if a is empty.
        """
        
        if self.a:
            self.b.insert(0, self.a.pop(0))
        self._do_action('pb')

    def ra(self):
        """Shifts up all elements of stack a by 1.
        The first element becomes the last one.
        If there is only one or no elements, do nothing.
        """
        
        if len(self.a) > 1:
            self.a.append(self.a.pop(0))
        self._do_action('ra')

    def rb(self):
        """Shifts up all elements of stack b by 1.
        The first element becomes the last one.
        If there is only one or no elements, do nothing.
        """
        
        if len(self.b) > 1:
            self.b.append(self.b.pop(0))
        self._do_action('rb')

    def rr(self):
        """Performs ra and rb at the same time."""
        
        if len(self.a) > 1:
            self.a.append(self.a.pop(0))
        if len(self.b) > 1:
            self.b.append(self.b.pop(0))
        self._do_action('rr')

    def rra(self):
        """Shifts down all elements of stack a by 1.
        The last element becomes the first one.
        If there is only one or no elements, do nothing.
        """
        
        if len(self.a) > 1:
            self.a.insert(0, self.a.pop())
        self._do_action('rra')

    def rrb(self):
        """Shifts down all elements of stack b by 1.
        The last element becomes the first one.
        If there is only one or no elements, do nothing.
        """
        
        if len(self.b) > 1:
            self.b.insert(0, self.b.pop())
        self._do_action('rrb')

    def rrr(self):
        """Performs rra and rrb at the same time."""
        
        if len(self.a) > 1:
            self.a.insert(0, self.a.pop())
        if len(self.b) > 1:
            self.b.insert(0, self.b.pop())
        self._do_action('rrr')
        
    def is_sorted(self):
        return self.a == sorted(self.a)
    
    def _sort_two(self, stack_name: str):
        if stack_name == 'a':
            stack = self.a
            r = self.ra
        else:
            stack = self.b
            r = self.rb
        # let a = [1, 2]
        # let top = a[0] = 1, bottom = a[1] = 2
        top, bottom = stack
        if top < bottom:    # 1, 2
            return
        else:                # 2, 1
            r()
        
    def _sort_three(self, stack_name: str):
        if stack_name == 'a':
            stack = self.a
            s = self.sa
        else:
            stack = self.b
            s = self.sb
        # let a = [1, 2, 3]
        # let top = a[0] = 1, middle = a[1] = 2, bottom = a[2] = 3
        top, middle, bottom = stack
        if top < middle < bottom:    # 1, 2, 3
            return
        elif top < bottom < middle:  # 1, 3, 2
            s()
        elif bottom < top < middle:  # 2, 3, 1
            return
        elif bottom < middle < top:  # 3, 2, 1
            s()
        elif middle < bottom < top:  # 3, 1, 2
            return
        else:                        # 2, 1, 3
            s()
            
    def _min(self, lst: list[int]):
        _len = len(lst)
        if _len == 0:
            return None
        if _len == 1:
            return lst[0]
        _min = lst[0]
        while _len:
            if _len == 1:
                break
            if lst[_len-1] < _min:
                _min = lst[_len-1]
            _len -= 1
        return _min
    
    def _max(self, lst: list[int]):
        _len = len(lst)
        if _len == 0:
            return None
        if _len == 1:
            return lst[0]
        _max = lst[0]
        while _len:
            if _len == 1:
                break
            if lst[_len-1] > _max:
                _max = lst[_len-1]
            _len -= 1
        return _max
    
    def _med(self, lst: list[int]):
        return (self._max(lst) + self._min(lst))/2
        sorted_lst = sorted(lst)
        middle_index = int((len(sorted_lst) - 1)/2)
        return sorted_lst[middle_index]
    
    def _to_top(self, nbr: int, stack_name: str):
        if stack_name == 'a':
            stack = self.a
        else:
            stack = self.b
        i = 0
        _len = len(stack)
        while stack[i] != nbr:
            i += 1
            if i == _len:
                return _len
        return i
    
    def _to_bottom(self, nbr: int, stack_name: str):
        if stack_name == 'a':
            stack = self.a
        else:
            stack = self.b
        i = 0
        _len = len(stack)
        while stack[i] != nbr:
            i += 1
            if i == _len:
                return 0
        return _len - 1 - i
  
    def _rot_to_top(self, nbr: int, stack_name: str):
        if stack_name == 'a':
            r = self.ra
            rr = self.rra
        else:
            r = self.rb
            rr = self.rrb
        to_top = self._to_top(nbr, stack_name)
        to_bot = self._to_bottom(nbr, stack_name)
        if to_top <= to_bot + 1:
            while to_top:
                r()
                to_top -= 1
        else:
            while to_bot + 1:
                rr()
                to_bot -= 1
                
    
    def _score(self, nbr: int):
        score = 0
        
        through_rb = self._to_top(nbr, 'b')
        through_rrb = self._to_bottom(nbr, 'b') + 1
            
        through_ra = 0
        a = copy(self.a)
        while not (a[0] > nbr and a[-1] < nbr):
            a.append(a.pop(0)) # ra
            through_ra += 1
            
        through_rra = 0
        a = copy(self.a)
        while not (a[0] > nbr and a[-1] < nbr):
            a.insert(0, a.pop()) # rra
            through_rra += 1
            
        through_rb_ra = max(through_rb, through_ra) 
        through_rrb_rra = max(through_rrb, through_rra) 
        through_rb_rra = through_rb + through_rra
        through_rrb_ra = through_rrb + through_ra
        
        min_op = min(through_rb_ra, through_rb_rra, through_rrb_ra, through_rrb_rra)
        score += min_op
        
        if min_op == through_rb_ra:
            diff = min(through_rb, through_ra)
            through_rb -= diff
            through_ra -= diff
            actions = [self.rr] * diff + [self.ra] * through_ra + [self.rb] * through_rb
        elif min_op == through_rrb_rra:
            diff = min(through_rrb, through_rra)
            through_rrb -= diff
            through_rra -= diff
            actions = [self.rrr] * diff + [self.rra] * through_rra + [self.rrb] * through_rrb
        elif min_op == through_rb_rra:
            actions = [self.rb] * through_rb + [self.rra] * through_rra
        elif min_op == through_rrb_ra:
            actions = [self.rrb] * through_rrb + [self.ra] * through_ra
            
        return score, actions
        
    def _sort_small(self):
        """a has 3 to 6 elements or less"""
            
        while len(self.a) > 3:
            _min = self._min(self.a)
            self._rot_to_top(_min, 'a')
            self.pb()

        self._sort_three('a')
        _min = self._min(self.a)
        self._rot_to_top(_min, 'a')

        while len(self.b) > 0:
            self.pa()


    def _sort_big(self):
        """a has more than 6 elements"""            
        _min = self._min(self.a)
        _med = self._med(self.a)
        _max = self._max(self.a)
        
        while len(self.a) > 3:
            el = self.a[0]
            if el in (_min, _max, _med):
                self.ra()
                continue
            elif el < _med:
                self.pb()
            else:
                self.pb()
                self.rb()
                
        self._sort_three('a')
        
        while self.b:
            scores = {}
            for b in self.b:
                score, actions = self._score(b)
                if score not in scores:
                    scores.update({score: actions})
                
            min_score = min(scores)
            actions = scores[min_score]
            for action in actions:
                action()
            self.pa()
            
        

    def sort(self):
        if self.print:
            print(f'Init:\t{self.a}')
            print('\n')
            
        if len(self.a) == 1:
            pass
        elif len(self.a) == 2:
            self._sort_two('a')
        elif len(self.a) >= 3 and len(self.a) < 7:
            self._sort_small()
        else:
            self._sort_big()
            
        _min = self._min(self.a)
        self._rot_to_top(_min, 'a')
        
        assert self.a == sorted(self.a), f"Not sorted: {self.a}"
        
        if self.print:
            print(f'Sorted:\t{self.a}')
                

"""
#lst = [3, 1, 2, 5, 4]
lst = [4, 3, 5, 1, 2, 6]
sorter = Sorter(lst, print=True)
sorter.sort()

"""










