shox
====

shox is a very simple and small implementatin of a shell and how it works.
Here you'll find parse, fork, exec and wait functions running as principals and another some ones.

Running conditions:
>> Commands must be on a single line.
>> Arguments must be separated by whitespace.
>> No quoting arguments or escaping whitespace.
>> Redirection in development, piping not yet.
>> All commands runs directly from your system path or current directory, but not cd, that is implemented on it.
* E.g.
* ls -lah
* ls /etc
* cat /etc/profile
* echo > file
* cat < file

Contributing
------------
Fell free to contribute and increase this code, I shall be very excited with your contribuitions.

License
-------
This code is in the public domain (see [UNLICENSE](UNLICENSE) for more details).
This means you can use, modify, and distribute it without any restriction.  I
appreciate, but don't require, acknowledgement in derivative works.

Github
------
Source code available at https://github.com/foxlollato/shox.git
