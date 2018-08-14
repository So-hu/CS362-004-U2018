

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   System.out.println("---------Manual Tests---------");
	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String[] Cases = {"http://foo.bar.com/","https://www.google.com/", "", "http://www.mysite.com:80/"};
	   Boolean result = true;
	   String out;
	   for (int index = 0; index < Cases.length; index++) {
		   result = urlValidator.isValid(Cases[index]);
		   if(result) {
			   out = "valid";
		   }
		   else {
			   out = "invalid";
		   }
		   System.out.println(Cases[index] + " " + out);
	   }
   }
   
   
   public void testIP()
   {
	   System.out.println("---------Testing IP---------");
	   UrlValidator urlValidator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
	   String[] Cases = {"-1.22.44.55", "0.0.0.0", "1.1.1.499", "255.255.255.255"};
	   Boolean result = true;
	   String out;
	   for (int index = 0; index < Cases.length; index++) {
		   result = urlValidator.isValid(Cases[index]);
		   if(result) {
			   out = "valid";
		   }
		   else {
			   out = "invalid";
		   }
		   System.out.println(Cases[index] + " " + out);
	   }
   }
   
   public void testScheme(){
	   System.out.println("---------Testing Schemes(https, ftp)---------");	 
	   String[] schemes = {"ftp", "https"};
	   UrlValidator urlValidator = new UrlValidator(schemes);
	   String[] Cases = {"http://foo.bar.com/","https://www.abc.com/", "ftp://www.mysite.com/"};
	   Boolean result = true;
	   String out;
	   for (int index = 0; index < Cases.length; index++) {
		   result = urlValidator.isValid(Cases[index]);
		   if(result) {
			   out = "valid";
		   }
		   else {
			   out = "invalid";
		   }
		   System.out.println(Cases[index] + " " + out);
	   }
   }   

}
