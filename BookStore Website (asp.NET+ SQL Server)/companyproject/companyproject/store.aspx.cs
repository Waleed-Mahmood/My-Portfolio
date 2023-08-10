using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using companyproject.DAL;
namespace companyproject
{
    public partial class store : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void onclickcat1(object sender, EventArgs e)
        {
            SQLConnectioncommand1.SelectCommand = "";
            SQLConnectioncommand1.SelectCommand = "Select * from Books where CategoryID=1";
        }
        protected void onclickcat2(object sender, EventArgs e)
        {
            SQLConnectioncommand1.SelectCommand = "";
            SQLConnectioncommand1.SelectCommand = "Select * from Books where CategoryID=2";
        }
        protected void onclickcat3(object sender, EventArgs e)
        {
            SQLConnectioncommand1.SelectCommand = "";
            SQLConnectioncommand1.SelectCommand = "Select * from Books where CategoryID=3";
        }
        protected void Ratingfunc(object source, CommandEventArgs e)
        {
            int bookid = Convert.ToInt32(e.CommandArgument);
            string url = "Ratings.aspx?id=" + bookid;
            Response.Redirect(url);
        }
        protected void search(object source, EventArgs e)
        {
            string bookt = Convert.ToString(TextBox3.Text.Trim());
            SignUpDAL objMyDal = new SignUpDAL();
            int found;
            found = objMyDal.checkbooktitleexists(bookt);
            if(found==1)
            {
                SQLConnectioncommand1.SelectParameters.Add("booktitl", System.Data.DbType.String, bookt);
                SQLConnectioncommand1.SelectCommand = "select * from Books where @booktitl=Title";
            }
            else
            {
                SQLConnectioncommand1.SelectCommand = "";
            }
        }
        protected void addtoCart_Click(object sender, EventArgs e)
        {
            int bid = Convert.ToInt32(TextBox10.Text.Trim());
            int quan = Convert.ToInt32(TextBox20.Text.Trim());

            SignUpDAL objMyDal = new SignUpDAL();

            double price;  //if book found, return price, else return -1
            price = objMyDal.userCart(bid, quan);
            if (price == -1)  //book doesn't exist
            {
                HttpContext.Current.Response.Write("<script>alert('No book of this id exist in database');</script>");
            }
            else if (price == -2)
            {
                HttpContext.Current.Response.Write("<script>alert('Available stock is less than your desired quantity');</script>");
            }
            else
            {
                Cart ycart = new Cart();
                if (Session["myCart"] == null)
                {
                    Session["myCart"] = ycart;
                }
                ycart = (Cart)Session["myCart"];



                string title = objMyDal.getTitle(bid);

                ycart.insert(new CartItem(bid, title, quan, price));
                HttpContext.Current.Response.RedirectPermanent("curcart.aspx");
            }
        }


    }

}
