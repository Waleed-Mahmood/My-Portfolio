using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace companyproject
{
    public partial class curcart : System.Web.UI.Page
    {
       protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["myCart"] == null)
            {
                Session["myCart"] = new Cart();
            }
            Cart myCart = (Cart)Session["myCart"];

            if (!IsPostBack)
            {
                myCart = (Cart)Session["myCart"];
                FillData();
            }
        }

        private void FillData()
        {
            Cart myCart = (Cart)Session["myCart"];
            HookOnBooksCart.DataSource = myCart.Items;
            HookOnBooksCart.DataBind();
            if (myCart.Items.Count == 0)
            {
                GrandTotal.Visible = false;
            }
            else
            {  //{0,19:C}
                GrandTotal.Text = string.Format("Grand Total = {0,19:C} ", myCart.GrandTotal);
                GrandTotal.Visible = true;
            }
        }
        protected void HookOnBooksCart_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            HookOnBooksCart.EditIndex = -1;
            FillData();
        }

        protected void HookOnBooksCart_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            Cart c = new Cart();
            c = (Cart)Session["myCart"];
            c.delete(e.RowIndex);
            FillData();
        }

        protected void HookOnBooksCart_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            TextBox txtQuantity = (TextBox)HookOnBooksCart.Rows[e.RowIndex].Cells[3].Controls[0];
            int quantity = Int32.Parse(txtQuantity.Text);
            Cart c = new Cart();
            c = (Cart)Session["myCart"];
            c.update(e.RowIndex, quantity);
            HookOnBooksCart.EditIndex = -1;
            FillData();
        }

        protected void HookOnBooksCart_RowEditing(object sender, GridViewEditEventArgs e)
        {
            HookOnBooksCart.EditIndex = e.NewEditIndex;

        }
    }
}