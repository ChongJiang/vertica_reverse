/*****************************
 * Vertica Analytic Database
 *
 * strcat User Defined Functions
 *
 * Copyright Vertica, 2012
 */

-- Step 1: Create LIBRARY 
\set libfile '\''`pwd`'/lib/reverse.so\'';
CREATE LIBRARY reverse AS :libfile;

-- Step 2: Create cube/rollup Factory
\set tmpfile '/tmp/strcatinstall.sql'
\! cat /dev/null > :tmpfile

\t
\o :tmpfile
select 'CREATE FUNCTION reverse AS LANGUAGE ''C++'' NAME '''||obj_name||''' LIBRARY reverse;' from user_library_manifest where lib_name='reverse' and obj_name like 'ReverseFactory%';

\o
\t

\i :tmpfile
\! rm -f :tmpfile
