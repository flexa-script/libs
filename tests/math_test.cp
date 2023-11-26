using cptest;
using math;


def abs_PositiveInt() {
  // arrange
  var num : int = 10;
  
  // act
  var res : int = abs(num);
  
  // assert
  assertEquals("absPositiveInt", 10, res);
}

def abs_NegativeInt() {
  // arrange
  var num : int = -10;
  
  // act
  var res : int = abs(num);
  
  // assert
  assertEquals("absNegativeInt", 10, res);
}

def abs_PositiveFloat() {
  // arrange
  var num : float = 6.667;
  
  // act
  var res : float = abs(num);
  
  // assert
  assertEquals("absPositiveFloat", 6.667, res);
}

def absNegativeFloat() {
  // arrange
  var num : float = -6.667;
  
  // act
  var res : float = abs(num);
  
  // assert
  assertEquals("absNegativeFloat", 6.667, res);
}

def math_test() {
  abs_PositiveInt();
  abs_NegativeInt();
  abs_PositiveFloat();
  abs_NegativeFloat();
}
