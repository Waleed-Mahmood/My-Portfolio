using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text;
using System.Text.RegularExpressions;
using companyproject.DAL;
using System.Data;

namespace companyproject
{
    public partial class signup : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        
        protected void SignUpButton_Click(object sender, EventArgs e)
        {
        
            String FirstName = TextBox3.Text.Trim(); //Trim method that trims a string from both ends by removing white spaces or a specified character or characters from the start and the end of a string.
            String lastName = TextBox4.Text.Trim(); 
            String password = TextBox2.Text.Trim(); 
            String gender = TextBox5.Text.Trim(); 
            String member = TextBox7.Text.Trim(); 
            String address = TextBox6.Text.Trim(); 
            String mail = TextBox1.Text.Trim();

            // check if any text box is empty or not
            if (String.IsNullOrEmpty(FirstName) || String.IsNullOrEmpty(lastName) || String.IsNullOrEmpty(password) ||
                String.IsNullOrEmpty(gender) || String.IsNullOrEmpty(member) || String.IsNullOrEmpty(address) || String.IsNullOrEmpty(mail))
            { }
            else
            {
                if (!(mail.Contains("@")))
                {
                    Response.Write("<script>alert('Enter valid email address');</script>");
                }
                bool checkGender = false, checkmember = false;
                if (string.Compare(gender, "m") == 0 || string.Compare(gender, "M") == 0 || string.Compare(gender, "F") == 0 || string.Compare(gender, "f") == 0)
                {
                    checkGender = true;
                }
                if (string.Compare(member, "0") == 0 || string.Compare(member, "1") == 0)
                {
                    checkmember = true;
                }
                if (checkGender == false)
                {
                    Response.Write("<script>alert('Gender can only be M or F');</script>");
                }
                if (checkmember == false)
                {
                    Response.Write("<script>alert('Members value can only be 1 or 0');</script>");
                }
                Regex RgxUrl = new Regex("[^A-Za-z0-9]"); //regular expression
                if (!(password.Any(char.IsUpper)) || !(password.Any(char.IsDigit)) || !(RgxUrl.IsMatch(password)))
                {
                    Response.Write("<script>alert('Password must contain atleast one Upper Case letter, atleast one digit and a special character. Kindly re-create password!');</script>");
                }
                else
                {
                    char g = Convert.ToChar(gender); //check-> only m/f 
                    char m = Convert.ToChar(member);  //check-> only 1/0
                    SignUpDAL objMyDal = new SignUpDAL();
                    int found;
                    found = objMyDal.SignUp(FirstName, lastName, password, g, m, address, mail);
                }
            }       
        }
    }
}