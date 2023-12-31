﻿<%@ Page Title="" Language="C#" MasterPageFile="~/admin.Master" AutoEventWireup="true" CodeBehind="DummyAdminProfile.aspx.cs" Inherits="companyproject.DummyAdminProfile" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <!DOCTYPE html>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <style>
        .card {
            box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
            max-width: 300px;
            margin: auto;
            text-align: center;
            font-family: arial;
        }

        .title {
            color: grey;
            font-size: 18px;
        }

        button {
            border: none;
            outline: 0;
            display: inline-block;
            padding: 8px;
            color: white;
            background-color: #000;
            text-align: center;
            cursor: pointer;
            width: 100%;
            font-size: 18px;
        }

        a {
            text-decoration: none;
            font-size: 22px;
            color: black;
        }

            button:hover, a:hover {
                opacity: 0.7;
            }
    </style>

    <h2 style="text-align: center">Admin Profile Card</h2>

    <div class="card">
        <img src="img/Dummy/dummyAdminProfile.jpg" alt="John" style="width: 100%" />
        <h1>John Doe</h1>
        <p class="title">CEO & Founder, Example</p>
        <p>Harvard University</p>
        <div style="margin: 24px 0;">
            <a href="https://dribbble.com/"><i class="fa fa-dribbble"></i></a>
            <a href="https://twitter.com/"><i class="fa fa-twitter"></i></a>
            <a href="https://www.linkedin.com/"><i class="fa fa-linkedin"></i></a>
            <a href="https://www.facebook.com/"><i class="fa fa-facebook"></i></a>
        </div>
        <p>
            <button>Contact</button></p>
    </div>

</asp:Content>

