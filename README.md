# loaded_die
## Fair and Loaded Die in C. 
This is a command line utility that simulates rolling a die a set number of times. The first argument determines the number of throws, and the second argument determines the number of sides on the die. The user has the option of rolling a loaded die (best of two rolls) by including the -l flag. 

This is an exercise in using function pointers with structs to allow functions to be called with dot-notation syntax as a method of creating polymorphism--i.e., we could create a bunch of "dice" structs, associate different methods of random-number generation (biased towards whatever values we favor), and activate them using the same syntax.

<div>
	<p>Salient features:</p>
	<ul>
		<li>line 7: struct member defined as function pointer</li>
		<li>line 46: assigning a "loaded roll" function to the pointer if flag is set</li>
		<li>line 49: assigning a "fair" function to the pointer if flag is not set</li>
	</ul>
</div>

<div>
	<img src="/example.png">
</div>
