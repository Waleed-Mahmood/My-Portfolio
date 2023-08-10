import React from 'react'
import './Navbar.css'
import Button from 'react-bootstrap/Button';
import Team from '../contact/contact'
import { Link, animateScroll as scroll } from "react-scroll";


export const TheNavbar = () => {

    return (

        <div className='nav-bar'>
            <div className='LogoName'>
                <h3>Quick Serve</h3>
            </div>
            <div className='SearchBar'>
                <div className='SearchBarIcon'>
                    <img src={"./assets/search.png"} />
                </div>
                <input className='SearchInput' placeholder='Collection' />
            </div>
            <ul className='NavBarItem'>
                <Link 
                    className='button'
                    activeClass="active"
                    to="home"
                    spy={true}
                    smooth={true}
                    offset={-70}
                    duration={500}
                >Home</Link>
                <Link 
                    className='button'
                    activeClass="active"
                    to="services"
                    spy={true}
                    smooth={true}
                    offset={-70}
                    duration={500}
                >Services</Link>
                <Link 
                    className='button'
                    activeClass="active"
                    to="contact"
                    spy={true}
                    smooth={true}
                    offset={-70}
                    duration={500}
                >Contact</Link>
                <Link 
                    className='button'
                    activeClass="active"
                    to="team"
                    spy={true}
                    smooth={true}
                    offset={-70}
                    duration={500}
                >Team</Link>
                <Link 
                    className='button'
                    activeClass="active"
                    to="signin"
                    spy={true}
                    smooth={true}
                    offset={-70}
                    duration={500}
                >Sign in</Link>
                   
            </ul>

        </div>

    )
}

export default TheNavbar