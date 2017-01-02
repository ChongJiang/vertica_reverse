

select reverse('1234567890') as r_value;

/**
Output should like followings:
  r_value   
------------
 0987654321
(1 row)
*/


select reverse('abcde') as r_value;

/**
Output should like followings:
 r_value 
---------
 edcba
(1 row)
*/


select reverse(NULL) is null as r_value;

/**
 r_value 
---------
 t
(1 row)
*/


select reverse('') is null as r_value;

/**
 r_value 
---------
 f
(1 row)
*/
