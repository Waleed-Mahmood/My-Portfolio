import { useCallback, useEffect, useRef, useState } from "react";
import { Link } from "react-router-dom";
import "./Gallery.css"

const slideStyles = {
    width: "100%",
    height: "100%",
    borderRadius: "10px",
    backgroundSize: "cover",
    backgroundPosition: "center",
    // border: "4px solid #ff014d",
};

const slidesContainerStyles = {
    display: "flex",
    height: "100%",
    transition: "transform ease-out 0.6s",
};


const ImageSlider = ({ slides, parentWidth, bio }) => {
    const timerRef = useRef(null);
    const [currentIndex, setCurrentIndex] = useState(0);
    const goToPrevious = () => {
        const isFirstSlide = currentIndex === 0;
        const newIndex = isFirstSlide ? slides.length - 1 : currentIndex - 1;
        setCurrentIndex(newIndex);
    };
    const goToNext = useCallback(() => {
        const isLastSlide = currentIndex === slides.length - 1;
        const newIndex = isLastSlide ? 0 : currentIndex + 1;
        setCurrentIndex(newIndex);
    }, [currentIndex, slides]);
    const goToSlide = (slideIndex) => {
        setCurrentIndex(slideIndex);
    };
    const getSlideStylesWithBackground = (slideIndex) => ({
        ...slideStyles,
        backgroundImage: `url(${slides[slideIndex].url})`,
        width: `${parentWidth}px`,
    });
    const getSlidesContainerStylesWithWidth = () => ({
        ...slidesContainerStyles,
        width: parentWidth * slides.length,
        transform: `translateX(${-(currentIndex * parentWidth)}px)`,
    });


    useEffect(() => {
        if (timerRef.current) {
            clearTimeout(timerRef.current);
        }
        timerRef.current = setTimeout(() => {
            goToNext();
        }, 2000);

        return () => clearTimeout(timerRef.current);
    }, [goToNext]);

    return (
        <div className="sliderStyles">
            <div>
                <div className="leftArrowStyles" onClick={goToPrevious}>
                    ❰
                </div>
                <div onClick={goToNext} className="rightArrowStyles">
                    ❱
                </div>
            </div>
            <div className="slidesContainerOverflowStyles">
                <div style={getSlidesContainerStylesWithWidth()}>
                    {slides.map((_, slideIndex) => (
                        <>
                            <div
                                key={slideIndex}
                                style={getSlideStylesWithBackground(slideIndex)}
                            >
                                <button className="slider-link-btn">
                                    <Link className="slider-link" to={`/Biography/${slideIndex + 1}`}>
                                        Read Bio !!!
                                    </Link>
                                </button>
                            </div>

                        </>
                    ))}
                </div>
            </div>
            <div className="dotsContainerStyles">
                {slides.map((slide, slideIndex) => (
                    <div
                        className="dotStyle"
                        key={slideIndex}
                        onClick={() => goToSlide(slideIndex)}
                    >
                        ●
                    </div>
                ))}
            </div>
        </div>
    );
};

export default ImageSlider;