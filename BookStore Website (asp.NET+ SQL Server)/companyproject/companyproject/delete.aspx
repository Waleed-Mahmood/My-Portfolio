<%@ Page Title="" Language="C#" MasterPageFile="~/admin.Master" AutoEventWireup="true" CodeBehind="delete.aspx.cs" Inherits="companyproject.delete" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
        <h3 Id="bolde">Enter Details Here</h3>
           <div class="tm-container-inner-2 tm-contact-section">
            <div class="row">
                <div class="col-md-6">
                    <form action="" method="POST" class="tm-contact-form">
                        <div class="form-group">

                            <h3>BookID:</h3>
                            <asp:TextBox ID="TextBox1" class="form-control" runat="server"></asp:TextBox>

                        </div>

                        <div class="form-group tm-d-flex">

                            <asp:Button ID="Button1" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="Delete" />
                        </div>
                    </form>
                </div>
            </div>
        </div>
     <br />
</asp:Content>
