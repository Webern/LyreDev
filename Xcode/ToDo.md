DONE - Add getPartSpec function to IPart (etc)
Use getPartSpec function to find out the number of staves in the part and set the musicxml staff->properties->staves element.
Add beaming support
eliminate these functions from IDuration -virtual Rational getDurBaseValue() const = 0; virtual String getDurBaseName() const = 0;
eliminate these functions from IDurDot -virtual Rational getDurBaseValue() const = 0; virtual String getDurBaseName() const = 0;
Add tests for getDurBase() for both IDuration and IDurDot
