<%@ Page Title="" Language="C#" MasterPageFile="~/admin.Master" AutoEventWireup="true" CodeBehind="admin.aspx.cs" Inherits="companyproject.admin1" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3 id="bolde">Enter Details Here</h3>
    <div class="tm-container-inner-2 tm-contact-section">
        <div class="row">
            <div class="col-md-6">
                <form action="" method="POST" class="tm-contact-form">

                    <div class="form-group">

                        <h3>ISBN:</h3>
                        <asp:TextBox ID="TextBox8" class="form-control" runat="server"></asp:TextBox>

                    </div>
                    <div class="form-group">

                        <h3>Author FirstName:</h3>
                        <asp:TextBox ID="TextBox3" class="form-control" runat="server"></asp:TextBox>

                    </div>
                    <div class="form-group">

                        <h3>Author LastName:</h3>
                        <asp:TextBox ID="TextBox4" class="form-control" runat="server"></asp:TextBox>


                    </div>

                    <div class="form-group">
                        <h3>Price:</h3>
                        <asp:TextBox ID="TextBox5" class="form-control" runat="server"></asp:TextBox>
                    </div>

                    <div class="form-group">

                        <h3>CategoryName:</h3>
                        <asp:TextBox ID="TextBox1" class="form-control" runat="server"></asp:TextBox>

                    </div>

                    <div class="form-group">
                        <h3>Stock:</h3>
                        <asp:TextBox ID="TextBox2" class="form-control" runat="server"></asp:TextBox>

                    </div>
                    <div class="form-group">
                        <h3>ImageLink:</h3>
                        <asp:TextBox ID="TextBox6" class="form-control" runat="server"></asp:TextBox>

                    </div>
                    <div class="form-group">
                        <h3>Discount(%):</h3>
                        <asp:TextBox ID="TextBox9" class="form-control" runat="server"></asp:TextBox>

                    </div>
                    <div class="form-group tm-d-flex">

                        <asp:Button ID="Button1" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="Insert" />
                    </div>
                </form>
            </div>
        </div>
    </div>
    <br />
</asp:Content>
