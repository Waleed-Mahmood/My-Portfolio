import React, { useState } from 'react'
import './Bottomnav.css'

import { AiOutlineHome, AiOutlineHeart, AiOutlineShoppingCart, AiOutlineUser, AiOutlineSearch } from "react-icons/ai";
import { RiTeamFill } from "react-icons/ri"
import { MdOutlineHomeRepairService } from "react-icons/md"
import { Link, animateScroll as scroll } from "react-scroll";

// import { AiOutlineHome, AiOutlineHeart, AiOutlineShoppingCart, AiOutlineUser, AiOutlineSearch } from 'react-icons/ai'

function Bottomnav() {
    const [activeNav, setActiveNav] = useState('#')
    return (
        <div class='navend'>

            <Link
                className='button'
                activeClass="active"
                to="home"
                spy={true}
                smooth={true}
                offset={-70}
                duration={500}
            ><AiOutlineHome /></Link>
            <Link
                className='button'
                activeClass="active"
                to="services"
                spy={true}
                smooth={true}
                offset={-70}
                duration={500}
            ><MdOutlineHomeRepairService /></Link>
            <Link
                className='button'
                activeClass="active"
                to="contact"
                spy={true}
                smooth={true}
                offset={-70}
                duration={500}
            ><AiOutlineSearch /></Link>

            <Link
                className='button'
                activeClass="active"
                to="team"
                spy={true}
                smooth={true}
                offset={-70}
                duration={500}
            ><RiTeamFill /></Link>

            <Link
                className='button'
                activeClass="active"
                to="signin"
                spy={true}
                smooth={true}
                offset={-70}
                duration={500}
            ><AiOutlineUser /></Link>

        </div>
    )
}

export default Bottomnav