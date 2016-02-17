Ages ago I coded-up a handful of [Jean Meeus'](http://en.wikipedia.org/wiki/Jean_Meeus) Astronomical Algorithms (from the book of the same name) in PERL then C, then C++, then JavaScript, and finally C#.  All that code is now scattered around on various backup disc.

This is an attempt to organize it again.  Unfortunately, I'm discovering that the files even within the same language are from various versions, and in some cases I lost the last version.

So as I find stuff, I am putting it here.

The first thing I plan to do is a unit test case driver for the C version.  The sun rise/set/transit code was working perfectly years ago when tested against Heavens Above and the US Navy AA site.  What I have here seems to be off by about 10 minutes?

The JavaScript version was used in my DreamWeaver CalMaker extension and I had started to objectify it.

Anyone is welcome to help through adding more functions, testing, writing drivers, etc.  I suggest obtaining a copy of Astronomical Algorithms from Willmann-Bell, Inc. if you can find one.