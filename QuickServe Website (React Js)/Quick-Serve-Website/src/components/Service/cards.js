import React from 'react'
import "./Servicestyle.css"
import Card from '@mui/material/Card';
import CardHeader from '@mui/material/CardHeader';
import CardMedia from '@mui/material/CardMedia';
import Avatar from '@mui/material/Avatar';
import { red } from '@mui/material/colors';

export default function Displaycard(props) {
  return (
    <>
      <a href="#">
        <div className='ServiceProviderCard'>
          <Card className="thumbnail" sx={{ maxWidth: 435, maxHeight: 450 }} >
            <CardHeader
              avatar={
                <Avatar variant="rounded" src={props.Logo} >  </Avatar>
              }
              title={<a href="#" className="styleoftext"> {props.Company} </a>}
            />
            <CardMedia
              component="img"
              height="300"
              width="435"
              image={props.Picture}
            />
          </Card>
        </div>
      </a>
    </>
  )
}

