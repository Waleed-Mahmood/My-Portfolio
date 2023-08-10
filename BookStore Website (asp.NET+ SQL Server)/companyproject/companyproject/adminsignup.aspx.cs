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
    public partial class adminsignup : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void SignUpButton_AClick(object sender, EventArgs e)
        {

            String firstName = TextBox30.Text.Trim(); //Trim method that trims a string from both ends by removing white spaces or a specified character or characters from the start and the end of a string.
            String lastName = TextBox40.Text.Trim();
            String password = TextBox20.Text.Trim();
            String cnic = TextBox60.Text.Trim();
            String mail = TextBox10.Text.Trim();

            //check if any text box is empty or not
            if (String.IsNullOrEmpty(firstName) || String.IsNullOrEmpty(lastName) || String.IsNullOrEmpty(password) ||
               String.IsNullOrEmpty(cnic) || String.IsNullOrEmpty(mail))
            {
               // Response.Write("<script>alert('All field must be filled in order to sign up. Kindly fill the left out fields');</script>");
            }
            else
            {
                Regex RgxUrl = new Regex("[^A-Za-z0-9]"); //regular expression
                if (!(mail.Contains("@")))
                {
                    Response.Write("<script>alert('Enter valid email address');</script>");
                }
                else if (!(password.Any(char.IsUpper)) || !(password.Any(char.IsDigit)) || !(RgxUrl.IsMatch(password)))
                {
                    Response.Write("<script>alert('Password must contain atleast one Upper Case letter, atleast one digit and a special character. Kindly re-create password!');</script>");
                }
                else
                {
                    SignUpDAL objMyDal = new SignUpDAL();
                    int found;
                    found = objMyDal.SignUpAdmin(mail, firstName, lastName, password, cnic);
                }


            }
        }
    }
}