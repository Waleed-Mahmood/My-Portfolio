import React from 'react';
import * as AiIcons from 'react-icons/ai';
import * as FaIcons from 'react-icons/fa';
import * as BiIcons from 'react-icons/bi';
import * as RiIcons from 'react-icons/ri';


export const SidebarData = [
    {
        title: 'Home',
        path: '/',
        icon: <AiIcons.AiFillHome />,
        cName: 'sidebar-text'
    },
    {
        title: 'Genre',
        path: '/Genre',
        icon: <BiIcons.BiCategoryAlt style={{ strokeWidth: "0.5" }} />,
        cName: 'sidebar-text'
    },
    {
        title: 'Movies',
        path: '/Movies',
        icon: <RiIcons.RiMovieFill />,
        cName: 'sidebar-text'
    },
    {
        title: 'TV Series',
        path: '/TvSeries',
        icon: <FaIcons.FaDesktop />,
        cName: 'sidebar-text'
    },
    {
        title: 'Blogs',
        path: '/BlogsHome',
        icon: <FaIcons.FaBlog />,
        cName: 'sidebar-text'
    },
    {
        title: 'BioGallery',
        path: '/BioGallery',
        icon: <RiIcons.RiGalleryFill />,
        cName: 'sidebar-text'
    },
    {
        title: 'Contact',
        path: '/Contact',
        icon: <FaIcons.FaEnvelopeOpenText />,
        cName: 'sidebar-text'
    },
    {
        title: 'Location',
        path: '/Location',
        icon: <FaIcons.FaSearchLocation />,
        cName: 'sidebar-text'
    },
    {
        title: 'About',
        path: '/About',
        icon: <RiIcons.RiInformationFill />,
        cName: 'sidebar-text'
    }
];