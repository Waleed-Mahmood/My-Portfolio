import React, { useLayoutEffect, useEffect, useRef, useState } from 'react'
import ImageSlider from '../components/Gallery'
import { BioData } from '../components/BioData';
import "./css/BioGallery.css"

const slides = [
    { url: "g1.jpg" },
    { url: "g2.jpg" },
    { url: "g3.jpg" },
    { url: "g4.jpg" },
    { url: "g5.jpg" },
];

function BioGallery() {
    const ref = useRef(null);
    // const [parentWidth, setWidth] = useState(0);

    const [parentWidth, setParentWidth] = useState(window.innerWidth);
    useEffect(() => {
        const handleWindowResize = () => {
            setParentWidth(window.innerWidth - 500);
        };

        window.addEventListener('resize', handleWindowResize);

        return () => {
            window.removeEventListener('resize', handleWindowResize);
        };
    });

    // useLayoutEffect(() => {
    //     setWidth(ref.current.offsetWidth);
    // }, []);

    console.log({ parentWidth });
    return (
        <div style={{ padding: "0px 250px 0px 250px" }}>
            <div className='biogallery-container' id='c1'>
                {/* console.log({parentWidth}); */}
                {/* <h2 style={{ color: 'white' }}>{parentWidth}</h2> */}


                <h1>READ BIOGRAPHIES</h1>
                <ImageSlider slides={slides} parentWidth={parentWidth} bio={BioData} />
            </div>
        </div>
    )
}

export default BioGallery