import React, { useState } from 'react'
import "./MovieItem.css"
import { Link } from 'react-router-dom';
import Player from "./Player"
import ReactPlayer from 'react-player';
import { downloadIcon } from '@progress/kendo-svg-icons';

export default function MovieItem({ movie }) {
    // const im = movie.cover;
    // console.log(movie[0].cover);
    const [isDownloadClicked, setIsClicked] = useState(false);

    const handleDownload = (vid) => {
        // try {
        //     const videoUrl = 'https://drive.google.com/file/d/1tQqH2TqtxE95jQz8m-jQXuKWb1Qy9Dyg/view?usp=share_link';
        //     const videoRequest = new Request(videoUrl);
        //     videoRequest.credentials = "omit";
        //     fetch(videoRequest)
        //         .then(() => {
        //             const link = document.createElement('a');
        //             link.href = videoUrl;
        //             link.setAttribute('download', 'waterfall.mp4');
        //             document.body.appendChild(link);
        //             link.click();
        //             document.body.removeChild(link);
        //         });
        // } catch (error) {
        //     console.error(error);
        // }
        // Define the file ID of the video you want to download
        // const fileId = '1tQqH2TqtxE95jQz8m-jQXuKWb1Qy9Dyg';

        // https://drive.google.com/file/d/1tQqH2TqtxE95jQz8m-jQXuKWb1Qy9Dyg/view?usp=sharing
        // Create a temporary anchor element
        const link = document.createElement('a');
        link.style.display = 'none';
        document.body.appendChild(link);

        // Set the href attribute of the anchor element to the download URL
        // `https://drive.google.com/uc?export=download&id=${fileId}`
        link.href = vid;
        // https://drive.google.com/file/d/1tQqH2TqtxE95jQz8m-jQXuKWb1Qy9Dyg/view?usp=sharing

        // Set the download attribute to the desired file name
        link.setAttribute('download', 'video.mp4');

        // Programmatically trigger a click event on the anchor element
        link.click();

        // Clean up by removing the anchor element
        document.body.removeChild(link);
    };

    return (

        <>

            {
                movie.map(movie => (
                    <div className='movieItem-wrap'>
                        <img className='movieItem-cover' src={movie.thumbnail} alt='cover' />
                        <p className='movieItem-category'>{movie.rating}</p>
                        <h3>{movie.title} - {movie.year}</h3>

                        <p className='movieItem-desc'>{movie.extract}</p>
                        <footer>
                            {/* <Link className='movieItem-link' to={`/Movie/${movie.id}`}>
                    </Link> */}
                            <button onClick={() => handleDownload(movie.down)}> Download </button>
                            <div style={{ margin: "30px" }}>
                                {
                                    <ReactPlayer
                                        key={movie.id}
                                        url={movie.vid}
                                        controls={true}
                                        width="640"
                                        height="360"
                                    />

                                }
                            </div>

                        </footer>
                    </div>
                ))}
        </>
    )

}