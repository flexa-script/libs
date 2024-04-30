using cptest;
using math;


def abs_positive() {
  // arrange
  var num : float = 6.667;
  
  // act
  var res : float = math.abs(num);
  
  // assert
  cptest.assertEquals("abs_positive", 6.667, res);
}

def abs_negative() {
  // arrange
  var num : float = -6.667;
  
  // act
  var res : float = math.abs(num);
  
  // assert
  cptest.assertEquals("abs_negative", 6.667, res);
}

def clamp_greater() {
  // arrange
  var num : float = 10;
  var min : float = -5;
  var max : float = 5;
  
  // act
  var res : float = math.clamp(num, min, max);
  
  // assert
  cptest.assertEquals("clamp_greater", 5., res);
}

def clamp_lower() {
  // arrange
  var num : float = -10;
  var min : float = -5;
  var max : float = 5;
  
  // act
  var res : float = math.clamp(num, min, max);
  
  // assert
  cptest.assertEquals("clamp_lower", -5., res);
}

def clamp_between() {
  // arrange
  var num : float = 0;
  var min : float = -5;
  var max : float = 5;
  
  // act
  var res : float = math.clamp(num, min, max);
  
  // assert
  cptest.assertEquals("clamp_between", 0., res);
}

def math_test() {
  abs_positive();
  abs_negative();
  clamp_greater();
  clamp_lower();
  clamp_between();
}
