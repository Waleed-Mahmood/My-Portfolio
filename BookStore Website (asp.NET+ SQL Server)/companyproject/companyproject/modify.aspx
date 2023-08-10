<%@ Page Title="" Language="C#" MasterPageFile="~/admin.Master" AutoEventWireup="true" CodeBehind="modify.aspx.cs" Inherits="companyproject.modify" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div class="tm-paging-links">
        <nav>
            <ul>
                <li class="tm-paging-item">
                    <asp:Button ID="Button2" class="tm-paging-link active" runat="server" Text="BookID" /></li>
                <li class="tm-paging-item">
                    <asp:Button ID="Button3" class="tm-paging-link" runat="server" Text="Price" /></li>
                <li class="tm-paging-item">
                    <asp:Button ID="Button4" class="tm-paging-link" runat="server" Text="Stock" /></li>
                 <li class="tm-paging-item">
                    <asp:Button ID="Button5" class="tm-paging-link" runat="server" Text="Discount" /></li>
            </ul>
        </nav>
    </div>


    <h3 id="bolde">Enter Details Here</h3>
    <div class="tm-container-inner-2 tm-contact-section">
        <div class="row">
            <div class="col-md-6">
                <form action="" method="POST" class="tm-contact-form">
                    <div class="form-group">

                        <h3>BookID:</h3>
                        <asp:TextBox ID="TextBox1" class="form-control" runat="server"></asp:TextBox>

                    </div>

                    <div class="form-group">
                        <h3>New BookID:</h3>
                        <asp:TextBox Type="password" ID="TextBox2" class="form-control" runat="server"></asp:TextBox>

                    </div>

                    <div class="form-group tm-d-flex">

                        <asp:Button ID="Button1" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="Make Change" />
                    </div>
                </form>
            </div>
        </div>
    </div>
    <br />
</asp:Content>
