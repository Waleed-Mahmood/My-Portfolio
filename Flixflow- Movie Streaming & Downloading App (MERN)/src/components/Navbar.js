import React, { useState } from 'react';
import * as FaIcons from 'react-icons/fa';
import * as AiIcons from 'react-icons/ai';
import * as RiIcons from 'react-icons/ri';
import { Link, useNavigate } from 'react-router-dom';
import { SidebarData } from './SidebarData';
import './Navbar.css';
import '../App.css';
import { IconContext } from 'react-icons';
import { useAuth0 } from "@auth0/auth0-react";
// import Picture1 from 'Picture1.png'
function Navbar() {
    const [sidebar, setSidebar] = useState(false);
    const { user, loginWithRedirect, logout, isAuthenticated } = useAuth0();
    const [searchKeyword, setSearchKeyword] = useState('');
    const history = useNavigate();
    const handleSearch = (e) => {
        if (searchKeyword.trim() !== '') {
            history(`/Movies/'${searchKeyword}`);
        }
    };
    const toggleSidebar = () => {
        setSidebar(!sidebar);
        const footer = document.getElementsByClassName("footer")[0];
        if (footer.style.display !== 'none') {
            footer.style.display = 'none';

        }
        else {
            footer.style.display = 'block';
        }

    }

    return (
        <>
            <IconContext.Provider value={{ color: 'white' }}>
                <div className='navbar'>
                    <Link to='#' className='sidebar-menu-bars'>
                        <FaIcons.FaBars onClick={toggleSidebar} />
                    </Link>
                    <Link to="/" style={{ height: '100%' }}>
                        <img src='Picture4.png' alt='logo' style={{ left: '80px', position: 'absolute', height: '100px' }}></img>
                    </Link>

                    <div className='navbar-right'>
                        <form className="search" id="search" action="search">
                            <input
                                type="text"
                                name="keyword"
                                placeholder="Enter your keywords"
                                value={searchKeyword}
                                onChange={(e) => setSearchKeyword(e.target.value)}
                            />
                            <button onClick={handleSearch} onChange={handleSearch} type="submit" title="Search">
                                <FaIcons.FaSearch color='red' />
                            </button>
                        </form>
                        <div className="navbar-right-login">

                            <Link to="Signup">
                                Signup
                            </Link>
                            {/* <span style={{ margin: '0' }}>Login/ Register </span> */}
                            {/* this will display Login button only if user isAuthenticated else logout btn */}
                            {
                                isAuthenticated ?
                                    <Link to="Login" >
                                        <RiIcons.RiLoginBoxLine style={{ height: "30px", width: "50px" }} />
                                        <button style={{ padding: '5px 5px', backgroundColor: '#ff014d', color: '' }} onClick={() => logout({ logoutParams: { returnTo: window.location.origin } })}>Logout</button>
                                    </Link>
                                    :
                                    <Link to="/">
                                        <RiIcons.RiLoginBoxLine style={{ height: "30px", width: "50px" }} />
                                        <button style={{ padding: '5px 5px', backgroundColor: '#ff014d', color: '' }} onClick={() => loginWithRedirect()}>Login</button>
                                    </Link>
                            }

                            {/* {
                                user.name === "admin@gmail.com" &&
                                <Link to="/Admin" />
                            } */}
                        </div>
                    </div>
                </div>

                <nav className={sidebar ? 'sidebar-menu active' : 'sidebar-menu'}>
                    <ul className='sidebar-menu-items' onClick={toggleSidebar}>
                        <li className='sidebar-toggle'>
                            <Link to='#' className='sidebar-menu-bars'>
                                <AiIcons.AiOutlineClose />
                            </Link>
                        </li>
                        {SidebarData.map((item, index) => {
                            return (
                                <li key={index} className={item.cName}>
                                    <Link to={item.path}>
                                        {item.icon}
                                        <span>{item.title}</span>
                                    </Link>
                                </li>
                            );
                        })}
                    </ul>
                </nav>
            </IconContext.Provider >
            <script>

            </script>

        </>
    );
}

export default Navbar;