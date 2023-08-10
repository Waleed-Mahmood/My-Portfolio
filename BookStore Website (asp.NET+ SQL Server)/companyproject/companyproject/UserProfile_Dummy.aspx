<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="UserProfile_Dummy.aspx.cs" Inherits="companyproject.UserDummy_Profile" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">

    <%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="UserProfile_Dummy.aspx.cs" Inherits="companyproject.UserProfile_Dummy" %>

    <asp:Content ID="Content3" ContentPlaceHolderID="head" runat="server">
    </asp:Content>
    <asp:Content ID="Content4" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
        <a href="uDummyProfile.scss">uDummyProfile.scss</a>
        <div class="container">
            <div class="card-wrapper">

                <div class="card">

                    <div class="card-image">
                        <img src="https://image.ibb.co/dUTfmJ/profile_img.jpg" alt="profile one">
                    </div>

                    <ul class="social-icons">
                        <li>
                            <a href="">
                                <i class="fab fa-facebook-f"></i>
                            </a>
                        </li>
                        <li>
                            <a href="">
                                <i class="fab fa-instagram"></i>
                            </a>
                        </li>
                        <li>
                            <a href="">
                                <i class="fab fa-twitter"></i>
                            </a>
                        </li>
                        <li>
                            <a href="">
                                <i class="fab fa-dribbble"></i>
                            </a>
                        </li>
                    </ul>

                    <div class="details">
                        <h2>John Smith
          <br>
                            <span class="job-title">UI Developer</span>
                        </h2>
                    </div>
                </div>
            </div>
            <!-- end box wrapper -->


            <%--        <div class="card-wrapper">--%>

            <%-- <div class="card profile-two">

                <div class="card-image profile-img--two">
                    <img src="https://image.ibb.co/c9rY6J/profile02.jpg" alt="profile two">
                </div>

                <ul class="social-icons">
                    <li>
                        <a href="">
                            <i class="fab fa-facebook-f"></i>
                        </a>
                    </li>
                    <li>
                        <a href="">
                            <i class="fab fa-instagram"></i>
                        </a>
                    </li>
                    <li>
                        <a href="">
                            <i class="fab fa-twitter"></i>
                        </a>
                    </li>
                    <li>
                        <a href="">
                            <i class="fab fa-dribbble"></i>
                        </a>
                    </li>
                </ul>

                <div class="details jane">
                    <h2>Jane Doe
              <br>
                        <span class="job-title">UI Designer</span>
                    </h2>
                </div>
            </div>
        </div>
        <!-- END box wrapper -->--%>
        </div>
        <!-- END container -->
    </asp:Content>

</asp:Content>
