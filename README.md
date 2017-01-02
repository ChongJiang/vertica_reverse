<html lang="zn_CN"> <head> <meta charset='utf-8'> <title>Reverse string for Vertica</title> </head> <body>

Reverse string for Vertica
==========
This is a Vertica User Defined Functions (UDF) for string reverse function, just like SQL Server's.

Syntax:
----------

REVERSE ( string )

Parameters:

 * string: input string.
 * (return): reversed string of input. 

Examples:
----------

<code><pre>
	select reverse('1234567890') as r_value;
	  r_value   
	------------
	 0987654321
	(1 row)
	
</code></pre>
<code><pre>
	select reverse('abcde') as r_value;
	 r_value 
	---------
	 edcba
	(1 row)
</code></pre>


Install, test and uninstall:
----------
Befoe build and install, g++ should be available(yum -y groupinstall "Development tools" && yum -y groupinstall "Additional Development" can help on this).

 * Build: make
 * Install: make install
 * Test: make run
 * Uninstall make uninstall

</body> </html>



