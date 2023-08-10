import React from 'react'

import './Team.css'

export const Team = ({ description, name, image }) => {
    return (
        <div className='collectionCard'>
            <img src={image} alt="" />
            <div className='imageText'>
                <h4>{name}</h4>
                <p>{description}</p>
            </div>
        </div>)
}

export default Team