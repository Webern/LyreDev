DONE - Add getPartSpec function to IPart (etc)
DONE - Use getPartSpec function to find out the number of staves in the part and set the musicxml staff->properties->staves element.

* Features
Add beaming support in musicxml
Add tuplet support in musicxml

* Cleanup
eliminate these functions from IDuration -virtual Rational getDurBaseValue() const = 0; virtual String getDurBaseName() const = 0;
eliminate these functions from IDurDot -virtual Rational getDurBaseValue() const = 0; virtual String getDurBaseName() const = 0;
Add tests for getDurBase() for both IDuration and IDurDot
