import React from 'react'
import './TeamWrapper.css'
import './Team.css'
import Team from './Team'
import backvideo from '../../Assets/DarkBackground.mp4';
export const TeamWrapper = ({ description, name, image }) => {
    return (
        <div className='TeamPics' >
            {/* <div className='video'>

            <video autoPlay loop muted>
                <source src={backvideo} type='video/mp4' />
            </video>
            
            </div> */}
            
            <div className='teams'>
                <div><Team description={'FAST Student'} name={'Munawar Hussain'} image={'./assets/cartoon.png'} /></div>
                <div><Team description={'FAST Student'} name={'Waleed'} image={'./assets/cartoon.png'} /></div>
                <div><Team description={'FAST Student'} name={'Areeb Saqib'} image={'./assets/cartoon.png'} /></div>
                <div><Team description={'FAST Student'} name={'Abdullah'} image={'./assets/cartoon.png'} /></div>
            </div>
        </div>
    )
}

export default TeamWrapper