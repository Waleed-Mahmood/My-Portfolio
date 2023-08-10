import React from 'react'
import ReactPlayer from 'react-player'
import './Player.css'

function Player(url) {
    return (

        <div className='player-wrapper'>
            console.log(url);
            <ReactPlayer
                className='react-player'
                url={url}
                width='100%'
                height='100%'
            />
        </div >
    );
}
export default Player;
