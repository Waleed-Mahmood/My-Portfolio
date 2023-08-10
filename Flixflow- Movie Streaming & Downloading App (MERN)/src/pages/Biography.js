import React, { useEffect, useState } from 'react'
import { useParams } from 'react-router';
import './css/Biography.css';
import { BioData } from '../components/BioData';
import { Link } from 'react-router-dom';
import { Button } from '@progress/kendo-react-buttons';
import { PDFExport, savePDF, PDFExportProps } from '@progress/kendo-react-pdf';

function Biography() {
    const { id } = useParams();
    const [bio, setBio] = useState();
    const pdfExportComponent = React.useRef(null);

    const generatePDF = (fileName) => {
        console.log(fileName);
        if (pdfExportComponent.current) {
            // savePDF(image.current);
            pdfExportComponent.current.save({ fileName } + '.pdf');
            // PDFExportProps(fileName + '.pdf');
        }
    }

    useEffect(() => {
        const found = BioData.find(obj => {
            return obj.id === parseInt(id);
        });
        if (found) {
            setBio(found);
        }
    }, []);

    return (
        <>
            <div className='bio-container' >
                <link rel="./css/Biography.css" href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700" />
                <Link className='bio-goBack' to='/BioGallery'>
                    <span> &#8592;</span> <span>Go Back</span>
                </Link>
                <button className="button b1" onClick={() => generatePDF(bio.name)}>Save as PDF</button>
                {bio ? (
                    <PDFExport ref={pdfExportComponent} fileName={bio.name + '.pdf'} paperSize="A4">
                        <div className='bio-wrap' id='bio-wrap'>
                            <header>
                                <h1>{bio.name}</h1>
                                <br />
                                <p className='bio-date'>Released On: {bio.createdAt}</p>
                                <h2>Directed By: {bio.authorName}</h2>

                                <div >
                                    <div className='bio-category' >
                                        {
                                            bio.job.map(tag =>
                                                <p>{tag}</p>
                                            )
                                        }
                                    </div>
                                </div>

                            </header>

                            <img src={"/" + bio.cover} alt='cover' crossOrigin="anonymous" />
                            <p className='bio-desc'>{bio.description}</p>
                        </div >
                    </PDFExport>

                ) : (
                    <div className='emptyList-wrap'>
                        <img src='/empty.gif' alt='empty' />
                    </div>
                )
                }
            </div >
        </>
    );
}
export default Biography