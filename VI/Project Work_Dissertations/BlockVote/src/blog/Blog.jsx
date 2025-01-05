import React from 'react';
import Article from '../components/article/Article';
import { blog01, blog02, blog03, blog04, blog05 } from './imports';
import './blog.css';

const Blog = () => {
  return(
  <div className="gpt3__blog section__padding" id="blog">
    <div className="gpt3__blog-heading">
      <h1 className="gradient__text">A lot is happening, <br /> We are blogging about it.</h1>
    </div>
    <div className="gpt3__blog-container">
      <div className="gpt3__blog-container_groupA">
      <a href="https://www.upgrad.com/blog/cryptography-in-blockchain/" className="card-link">
        <Article imgUrl={blog01} date="Sep 26, 2021" text="Cryptography in Blockchain: Types & Applications [2023]" />
        </a>
      </div>
      <div className="gpt3__blog-container_groupB">
      
      <a href="https://blogs.oracle.com/blockchain/post/blockchain-interoperability-is-the-focus-of-december-obp-update" className="card-link">
        <Article imgUrl={blog02} date="Aug 26, 2022" text="Latest OCI Blockchain Platform update enables blockchain interoperability and brings Web3 capabilities to OCI" />
        </a>

        <a href="https://www.apriorit.com/dev-blog/734-blockchain-for-e-voting-systems" className="card-link">
        <Article imgUrl={blog03} date="Sep 26, 2023" text="Building an E-Voting System using Blockchain: Opportunities and Challenges" />
        </a>

        <a href="https://timesofindia.indiatimes.com/blogs/voices/how-can-blockchain-drive-transparency-in-supply-chain/" className="card-link">
        <Article imgUrl={blog04} date="Oct 28, 2023" text="How can blockchain drive transparency in supply chain" />
        </a>

        <a href="https://www.upgrad.com/blog/reasons-why-blockchain-technology-is-the-future/" className="card-link">
        <Article imgUrl={blog05} date="Nov 26, 2023" text="Blockchain is the future. Let us exlore how it is?" />
        </a>
      </div>
    </div>
  </div>
  );
  };

export default Blog;
